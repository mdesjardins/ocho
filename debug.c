
#include <stdio.h>
#include "core.h"
#include "instr.h"

void dump_memory_to_console() {
    for (int i=0; i<MEMORY_SIZE; i++) {
        if ((i % 32) == 0) {
            printf("\n%03x-%03x: ", i, i+31);
        }
        printf("%02x ", *(mem+i)); 
    }
}

void trace() {
    unsigned short* instruction;
    instruction = mem + pc_reg;
    if (*instruction != 0) {
        int i;
        for (i=0; i<NUM_REGISTERS/2; i++) {
            printf("v%02x:%04x ", i, v_reg[i]);
        }
        printf("pc:%x", pc_reg);

        unsigned short* instruction;
        instruction = mem + pc_reg;

        printf("\n>>>>>>>>> instruction: %x\n", *instruction);   
        printf(">>>>>>>>>> mem[pc_reg]: %x\n", mem[pc_reg]);
        printf(">>>>>>>>>> mem[pc_reg+1]: %x\n", mem[pc_reg+1]);

        unsigned char msb = (0xF000 & *instruction) >> 12;
        printf(">>>>>>>>>> msb: %x\n", msb);
        char instr_text[16];
        (*disassem_instr_ptr[msb])(*instruction, instr_text);

        printf("  %04x  %s\n\r", *instruction, instr_text);

        for (; i<NUM_REGISTERS; i++) {
            printf("v%02x:%04x ", i, v_reg[i]);
        }
        printf("i: %x\n\r", i_reg);
    }
}