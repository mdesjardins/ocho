#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include "core.h"
#include "debug.h"
#include "instr.h"
#include "term.h"

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
  init_term();
  init_core();

  int dump_memory = 0;


  int opt;
  while ((opt = getopt(argc, argv, "d")) != -1) {
    switch (opt) {
      case 'd':
        printf("debug: memory dump\n");
        dump_memory = 1;
        break;
    }
  }

  if (optind == argc) {
    printf("No ROM file provided\n");
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

    process_instruction(*instruction);
    pc_reg += sizeof(unsigned short);  // each instruction is 2 bytes
  }

  if (dump_memory) {
    printf("Memory:\n");
    dump_memory_to_console();
  }

  
}