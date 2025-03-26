#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "debug.h"
#include "instr.h"

void process_instruction(unsigned short instruction) {
  char high_nybble = (instruction & 0xf000) >> 12;
  (*instr_ptr[high_nybble])(instruction);
}

int main(int argc, char** argv) {
  init_core();

  if (argc < 2) {
    fprintf(stderr, "cartridge name as arg argc was %d\n", argc);
    exit(-1);
  }

  // load the ROM.  
  FILE* fp = fopen(argv[1], "rb");
  int i = fread((void *)(mem + PROGRAM_START_OFFSET), sizeof(char), MEMORY_SIZE-PROGRAM_START_OFFSET, fp);

  // start the fun. this assumes the host OS has the same endian-ness as 
  // the CHIP8 (most significant byte first).
  pc_reg = PROGRAM_START_OFFSET;
  unsigned short* instruction;
  while (pc_reg < MEMORY_SIZE) {
    instruction = mem + pc_reg;
    trace();
    process_instruction(*instruction);
    pc_reg++;
  }

  // printf("Memory:\n");
  // dump_memory_to_console();
}


