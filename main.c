#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include "core.h"
#include "debug.h"
#include "instr.h"
#include "term.h"

FILE* user_log_file = NULL;

void signal_handler(int sig) {
  log("\nReceived signal %d, cleaning up...\n", sig);
  if (user_log_file != NULL) {
    fclose(user_log_file);
  }
  cleanup_term();
  exit(1);
}

void process_instruction(unsigned short instruction) {
  char high_nybble = (instruction & 0xf000) >> 12;
  (*instr_ptr[high_nybble])(instruction);
}

void fix_endianness(unsigned char* mem, int size) {
  for (int i = 0; i < size; i += 2) {
    // Swap mem[i] and mem[i+1]
    unsigned char tmp = mem[i];
    mem[i] = mem[i+1];
    mem[i+1] = tmp;
  }
}


int main(int argc, char** argv) {
  // Set up signal handlers
  signal(SIGINT, signal_handler);   // Ctrl+C
  signal(SIGTERM, signal_handler);  // Termination request
  signal(SIGSEGV, signal_handler);  // Segmentation fault
  
  init_term();
  init_core();

  int dump_memory = 0;
  
  int opt;
  while ((opt = getopt(argc, argv, "d")) != -1) {
    switch (opt) {
      case 'd':
        log("debug: memory dump\n");
        dump_memory = 1;
        break;
      case 'h':
        log("Usage: %s [-d] rom_file\n", argv[0]);
        log("  -d: dump memory to console\n");
        log("  -h: show this help message\n");
        return 0;
        break;
      case 'l':
        user_log_file = fopen(optarg, "w");
        if (user_log_file == NULL) {
          log("Failed to open log file: %s\n", optarg);
          return 1;
        }
        log_file = user_log_file;
        break;
    }
  }

  if (optind == argc) {
    log("No ROM file provided\n");
    return 1;
  }

  // load the ROM.  
  FILE* fp = fopen(argv[optind], "rb");
  int i = fread((void *)(mem + PROGRAM_START_OFFSET), sizeof(char), MEMORY_SIZE-PROGRAM_START_OFFSET, fp);
  fclose(fp);

  fix_endianness(mem, MEMORY_SIZE);

  cleanup_term();
  
  // start the fun. this assumes the host OS has the same endian-ness as 
  // the CHIP8 (most significant byte first).
  pc_reg = PROGRAM_START_OFFSET;
  unsigned short* instruction;
  while (pc_reg < MEMORY_SIZE) {
    instruction = mem + pc_reg;
    trace();
    pc_reg += sizeof(unsigned short);  // each instruction is 2 bytes
    process_instruction(*instruction);
  }

  if (dump_memory) {
    log("Memory:\n");
    dump_memory_to_console();
  }

  if (user_log_file != NULL) {
    fclose(user_log_file);
  }
}