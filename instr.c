#include <stdio.h>
#include <string.h>
#include "core.h"
#include "instr.h"
#include "term.h"

void _stack_push(unsigned short addr) {
    //stack[stack_ptr++] = addr;
}

void _stack_pop(void) {
    //return stack[--stack_ptr];
}

void instr_0_family(unsigned short instruction) {
    if (instruction == 0x00e0) {
        clear();
    } else if (instruction == 0x00ee) {
        //return_from_subroutine();
    }
}  // 0xxx is a special case.
void disassem_instr_0_family(unsigned short instruction, char* text_out) {    
    if (instruction == 0x00e0) {
        strcpy(text_out, "CLS");
    } else if (instruction == 0x00ee) {
        strcpy(text_out, "RET");
    }
    return;
}  

// 1nnn - JP addr
// Jump to location nnn.
//
// The interpreter sets the program counter to nnn.
void instr_jump_immed(unsigned short instruction)  {
   unsigned short addr = instruction & 0xFFF;
   pc_reg = addr;
   return;
} // 1
void disassem_instr_jump_immed(unsigned short instruction, char* text_out)  {
   unsigned short addr = instruction & 0xFFF;
   sprintf(text_out, "JP %04x", addr); 
   return;
} // 1


// 2nnn - CALL addr
// Call subroutine at nnn.
//
// The interpreter increments the stack pointer, then puts the current PC on the top of the stack. The PC is then set to nnn.
void instr_call(unsigned short instruction)  {
    unsigned short addr = instruction & 0xFFF;
    stack[sp_reg++] = pc_reg;
    pc_reg = addr;
    return;
} // 2
void disassem_instr_call(unsigned short instruction, char* text_out)  {
   unsigned short addr = instruction & 0xFFF;
   sprintf(text_out, "CALL %04x", addr); 
   return;
} // 2



// 3xkk - SE Vx, byte
// Skip next instruction if Vx = kk.
//
// The interpreter compares register Vx to kk, and if they are equal, increments the program counter by 2.
void instr_skip_if_eq_immed(unsigned short instruction)  {

} // 3
void disassem_instr_skip_if_eq_immed(unsigned short instruction, char* text_out)  {
    unsigned char reg = (instruction & 0x0F00) >> 8;
    unsigned short immed = instruction & 0xFF;
    sprintf(text_out, "SE V%X,%x", reg, immed);
    return;
} // 3

// 4xkk - SNE Vx, byte
// Skip next instruction if Vx != kk.
//
// The interpreter compares register Vx to kk, and if they are not equal, increments the program counter by 2.
void instr_skip_if_ne_immed(unsigned short instruction)  {
    //printf("4: %x\n", instruction);
} // 4
void disassem_instr_skip_if_ne_immed(unsigned short instruction, char* text_out)  {
    unsigned char reg = (instruction & 0x0F00) >> 8;
    unsigned short immed = instruction & 0xFF;
    sprintf(text_out, "SNE V%X,%x", reg, immed);
    return;
} // 4

// 5xy0 - SE Vx, Vy
void instr_skip_if_eq_reg(unsigned short instruction)  {
    //printf("5: %x\n", instruction);
} // 5
void disassem_instr_skip_if_eq_reg(unsigned short instruction, char* text_out)  {
    //printf("5: %x\n", instruction);
    unsigned char reg0 = (instruction & 0x0F00) >> 8;
    unsigned char reg1 = (instruction & 0x00F0) >> 4;
    sprintf(text_out, "SE V%X,V%X", reg0, reg1);
    return;
} // 5

// 6xkk - LD Vx, byte
// Set Vx = kk.
//
// The interpreter puts the value kk into register Vx.
void instr_load_immed(unsigned short instruction)  {
    //printf("6: %x\n", instruction);
} // 6
void disassem_instr_load_immed(unsigned short instruction, char* text_out)  {
    unsigned char reg = (instruction & 0x0F00) >> 8;
    unsigned short immed = instruction & 0xFF;
    sprintf(text_out, "LD V%X,%x", reg, immed);
    return;
} // 6

// 7xkk - ADD Vx, byte
// Set Vx = Vx + kk.
//
// Adds the value kk to the value of register Vx, then stores the result in Vx.
void instr_add_immed(unsigned short instruction) {
    //printf("7: %x\n", instruction);
}  // 7
void disassem_instr_add_immed(unsigned short instruction, char* text_out) {
    unsigned char reg = (instruction & 0x0F00) >> 8;
    unsigned short immed = instruction & 0xFF;
    sprintf(text_out, "ADD V%X,%x", reg, immed);
    return;
}  // 7

// 8xy0 - LD Vx, Vy
// Set Vx = Vy.
//
// The values of Vx and Vy are swapped.
void instr_8_family(unsigned short instruction)  {
    //printf("8: %x\n", instruction);
} // 8
void disassem_instr_8_family(unsigned short instruction, char* text_out)  {
    unsigned char subinstr = instruction & 0xF;
    unsigned char reg0 = (instruction & 0x0F00) >> 8;
    unsigned char reg1 = (instruction & 0x00F0) >> 4;
    char cmd[5];
    switch(subinstr) {
        case 0x0:
            strncpy(cmd, "LD", sizeof(cmd));
            break;
        case 0x1:
            strncpy(cmd, "OR", sizeof(cmd));
            break;
        case 0x2:
            strncpy(cmd, "AND", sizeof(cmd));
            break;
        case 0x3:
            strncpy(cmd, "XOR", sizeof(cmd));
            break;
        case 0x4:
            strncpy(cmd, "ADD", sizeof(cmd));
            break;
        case 0x5:
            strncpy(cmd, "SUB", sizeof(cmd));
            break;
        case 0x6:
            strncpy(cmd, "SHR", sizeof(cmd));
            break;
        case 0x7:
            strncpy(cmd, "SUBN", sizeof(cmd));
            break;
        case 0xE:
            strncpy(cmd, "SHL", sizeof(cmd));
            break;
    }
    sprintf(text_out, "%s V%X,V%X", cmd, reg0, reg1);
    return;
} // 8

// 9xy0 - SNE Vx, Vy
// Skip next instruction if Vx != Vy.
//
// The values of Vx and Vy are compared, and if they are not equal, the program counter is increased by 2.
void instr_skip_if_ne_reg(unsigned short instruction)  {
    //printf("9: %x\n", instruction);
} // 9
void disassem_instr_skip_if_ne_reg(unsigned short instruction, char* text_out)  {
    unsigned char reg0 = (instruction & 0x0F00) >> 8;
    unsigned char reg1 = (instruction & 0x00F0) >> 4;
    sprintf(text_out, "SNE V%X,V%X", reg0, reg1);
    return;
} // 9

void instr_load_i_reg(unsigned short instruction)  {
    i_reg = instruction & 0x0FFF;
} // A
void disassem_instr_load_i_reg(unsigned short instruction, char* text_out)  {
    unsigned short immed = instruction & 0x0FFF;
    sprintf(text_out, "LD I,%x", immed);
    return;
} // A

// Bnnn - JP V0, addr
// Jump to location nnn + V0.
//
// The offset of the jump is stored in register V0. 
void instr_jump_offset(unsigned short instruction)  {
    //printf("B: %x\n", instruction);
} // B
void disassem_instr_jump_offset(unsigned short instruction, char* text_out)  {
    unsigned short immed = instruction & 0x0FFF;
    sprintf(text_out, "JP V0,%x", immed);
    return;
} // B

// Cxkk - RND Vx, byte
// Set Vx = random byte AND kk.
//
// The interpreter generates a random number from 0 to 255, which is then ANDed with the value kk. The result is stored in Vx.
void instr_rand(unsigned short instruction)  {
    //printf("C: %x\n", instruction);
} // C
void disassem_instr_rand(unsigned short instruction, char* text_out)  {
    unsigned char reg = (instruction & 0x0F00) >> 8;
    unsigned short immed = instruction & 0xFF;
    sprintf(text_out, "RND V%X,%x", reg, immed);
    return;
} // C

// Dxyn - DRW Vx, Vy, nibble
// Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
//
// The interpreter reads n bytes from memory, starting at the address stored in I. These bytes are then displayed as sprites on screen.
//
void instr_display(unsigned short instruction)  {
    //printf("D: %x\n", instruction);
} // D
void disassem_instr_display(unsigned short instruction, char* text_out)  {
    unsigned char reg0 = (instruction & 0x0F00) >> 8;
    unsigned char reg1 = (instruction & 0x00F0) >> 4;
    unsigned char nib = instruction & 0x000F;
    sprintf(text_out, "DRW V%X,V%X,%x", reg0, reg1, nib);
    return;
} // D

void instr_e_family(unsigned short instruction)  {
    //printf("E: %x\n", instruction);
    unsigned char subinstr = instruction & 0x00FF;
    unsigned char reg = instruction & 0x0F00 >> 8;

    if (subinstr == 0x9e) {
        // SKP Vx
        if (key_pressed(v_reg[reg])) {
            pc_reg += 2;
        }
    } else if (instruction == 0xa1) {
        // SKNP Vx  
        if (!key_pressed(v_reg[reg])) {
            pc_reg += 2;
        }
    }
    return;
} // E special
void disassem_instr_e_family(unsigned short instruction, char* text_out)  {
    unsigned char subinstr = instruction & 0x00FF;
    unsigned char reg = instruction & 0x0F00 >> 8;
    if (subinstr == 0x9e) {
        sprintf(text_out, "SKP V%X", reg);
    } else if (subinstr == 0xa1) {
        sprintf(text_out, "SKNP V%X", reg);
    } else {
        sprintf(text_out, "Invalid E instruction: %x", instruction);
    }
    return;
} // E

void instr_f_family(unsigned short instruction)  {
    //printf("F: %x\n", instruction);
} // F special
void disassem_instr_f_family(unsigned short instruction, char* text_out)  {
    unsigned char subinstr = instruction & 0x00FF;
    unsigned char reg = instruction & 0x0F00 >> 8;
    switch(subinstr) {
        case 0x07:
            sprintf(text_out, "SKP V%X", reg);
            break;
        case 0x0a:
            sprintf(text_out, "LD V%X,K", reg);
            break;
        case 0x15:
            sprintf(text_out, "LD DT,V%X", reg);
            break;
        case 0x18:
            sprintf(text_out, "LD ST,V%X", reg);
            break;
        case 0x1e:
            sprintf(text_out, "ADD I,V%X", reg);
            break;
        case 0x29:
            sprintf(text_out, "LD F,V%X", reg);
            break;
        case 0x33:
            sprintf(text_out, "LD B,V%X", reg);
            break;
        case 0x55:
            sprintf(text_out, "LD [I],V%X", reg);
            break;
        case 0x65:
            sprintf(text_out, "LD V%X,[I]", reg);
            break;
    }
    return;
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

void (*disassem_instr_ptr[16])(unsigned short, char*) = {
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
