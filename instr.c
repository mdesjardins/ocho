#include <stdio.h>
#include "core.h"
#include "instr.h"


void instr_0_family(unsigned short instruction) {
    //printf("0: %x\n", instruction);
}  // 0xxx is a special case.
void disassem_instr_0_family(unsigned short instruction, unsigned char* text_out) {
    //printf("0: %x\n", instruction);
}  // 0xxx is a special case.

void instr_jump_immed(unsigned short instruction)  {
    //printf("1: %x\n", instruction);
} // 1
void disassem_instr_jump_immed(unsigned short instruction, unsigned char* text_out)  {
    //printf("1: %x\n", instruction);
} // 1

void instr_call(unsigned short instruction)  {
    //printf("2: %x\n", instruction);
} // 2
void disassem_instr_call(unsigned short instruction, unsigned char* text_out)  {
    //printf("2: %x\n", instruction);
} // 2

void instr_skip_if_eq_immed(unsigned short instruction)  {
    //printf("3: %x\n", instruction);
} // 3
void disassem_instr_skip_if_eq_immed(unsigned short instruction, unsigned char* text_out)  {
    //printf("3: %x\n", instruction);
} // 3

void instr_skip_if_ne_immed(unsigned short instruction)  {
    //printf("4: %x\n", instruction);
} // 4
void disassem_instr_skip_if_ne_immed(unsigned short instruction, unsigned char* text_out)  {
    //printf("4: %x\n", instruction);
} // 4

void instr_skip_if_eq_reg(unsigned short instruction)  {
    //printf("5: %x\n", instruction);
} // 5
void disassem_instr_skip_if_eq_reg(unsigned short instruction, unsigned char* text_out)  {
    //printf("5: %x\n", instruction);
} // 5

void instr_load_immed(unsigned short instruction)  {
    //printf("6: %x\n", instruction);
} // 6
void disassem_instr_load_immed(unsigned short instruction, unsigned char* text_out)  {
    //printf("6: %x\n", instruction);
} // 6

void instr_add_immed(unsigned short instruction) {
    //printf("7: %x\n", instruction);
}  // 7
void disassem_instr_add_immed(unsigned short instruction, unsigned char* text_out) {
    //printf("7: %x\n", instruction);
}  // 7

void instr_8_family(unsigned short instruction)  {
    //printf("8: %x\n", instruction);
} // 8xxx is a special case.
void disassem_instr_8_family(unsigned short instruction, unsigned char* text_out)  {
    //printf("8: %x\n", instruction);
} // 8xxx is a special case.

void instr_skip_if_ne_reg(unsigned short instruction)  {
    //printf("9: %x\n", instruction);
} // 9
void disassem_instr_skip_if_ne_reg(unsigned short instruction, unsigned char* text_out)  {
    //printf("9: %x\n", instruction);
} // 9

void instr_load_i_reg(unsigned short instruction)  {
    //printf("A: %x\n", instruction);
} // A
void disassem_instr_load_i_reg(unsigned short instruction, unsigned char* text_out)  {
    //printf("A: %x\n", instruction);
} // A

void instr_jump_offset(unsigned short instruction)  {
    //printf("B: %x\n", instruction);
} // B
void disassem_instr_jump_offset(unsigned short instruction, unsigned char* text_out)  {
    //printf("B: %x\n", instruction);
} // B

void instr_rand(unsigned short instruction)  {
    //printf("C: %x\n", instruction);
} // C
void disassem_instr_rand(unsigned short instruction, unsigned char* text_out)  {
    //printf("C: %x\n", instruction);
} // C

void instr_display(unsigned short instruction)  {
    //printf("D: %x\n", instruction);
} // D
void disassem_instr_display(unsigned short instruction, unsigned char* text_out)  {
    //printf("D: %x\n", instruction);
} // D

void instr_e_family(unsigned short instruction)  {
    //printf("E: %x\n", instruction);
} // E special
void disassem_instr_e_family(unsigned short instruction, unsigned char* text_out)  {
    //printf("E: %x\n", instruction);
} // E special

void instr_f_family(unsigned short instruction)  {
    //printf("F: %x\n", instruction);
} // F special
void disassem_instr_f_family(unsigned short instruction, unsigned char* text_out)  {
    //printf("F: %x\n", instruction);
} // F special

void (*instr_ptr[16])(unsigned short) = {
  instr_0_family,  // 0xxx is a special case.
  instr_jump_immed, // 1
  instr_call, // 2
  instr_skip_if_eq_immed, // 3
  instr_skip_if_ne_immed, // 4
  instr_skip_if_eq_reg, // 5
  instr_load_immed, // 6
  instr_add_immed,  // 7
  instr_8_family, // 8xxx is a special case.
  instr_skip_if_ne_reg, // 9
  instr_load_i_reg, // A
  instr_jump_offset, // B
  instr_rand, // C
  instr_display, // D
  instr_e_family, // E special
  instr_f_family, // F special
};

void (*disassem_instr_ptr[16])(unsigned short, unsigned char*) = {
  disassem_instr_0_family,  // 0xxx is a special case.
  disassem_instr_jump_immed, // 1
  disassem_instr_call, // 2
  disassem_instr_skip_if_eq_immed, // 3
  disassem_instr_skip_if_ne_immed, // 4
  disassem_instr_skip_if_eq_reg, // 5
  disassem_instr_load_immed, // 6
  disassem_instr_add_immed,  // 7
  disassem_instr_8_family, // 8xxx is a special case.
  disassem_instr_skip_if_ne_reg, // 9
  disassem_instr_load_i_reg, // A
  disassem_instr_jump_offset, // B
  disassem_instr_rand, // C
  disassem_instr_display, // D
  disassem_instr_e_family, // E special
  disassem_instr_f_family, // F special
};

char* instr_text[16] = {
    "-", // 0
    "JPI", // 1
    "CALL", // 2
    "SEI", // 3
    "SNEI", // 4
    "SE", // 5
    "LDI", // 6
    "ADDI", // 7
    "-", // 8
    "SNE", // 9
    "LI", // A
    "JP", // B
    "RAND", // C
    "DISP", // D
    "-", // E
    "-", // F
};
