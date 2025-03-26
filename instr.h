#ifndef __INSTR_H__
#define __INSTR_H__

extern void instr_0_family(unsigned short instruction);  // 0xxx is a special case.
extern void instr_jump_immed(unsigned short instruction); // 1
extern void instr_call(unsigned short instruction); // 2
extern void instr_skip_if_eq_immed(unsigned short instruction); // 3
extern void instr_skip_if_ne_immed(unsigned short instruction); // 4
extern void instr_skip_if_eq_reg(unsigned short instruction); // 5
extern void instr_load_immed(unsigned short instruction); // 6
extern void instr_add_immed(unsigned short instruction);  // 7
extern void instr_8_family(unsigned short instruction); // 8xxx is a special case.
extern void instr_skip_if_ne_reg(unsigned short instruction); // 9
extern void instr_load_i_reg(unsigned short instruction); // A
extern void instr_jump_offset(unsigned short instruction); // B
extern void instr_rand(unsigned short instruction); // C
extern void instr_display(unsigned short instruction); // D
extern void instr_e_family(unsigned short instruction); // E special
extern void instr_f_family(unsigned short instruction); // F special

// Disassembly functions used for tracing. The opcode is
// passed in as an instruction, and the resulting string
// representation is placed at the address pointed to by
// text_out. 
extern void disassem_instr_0_family(unsigned short instruction, unsigned char* text_out);  // 0xxx is a special case.
extern void disassem_instr_jump_immed(unsigned short instruction, unsigned char* text_out); // 1
extern void disassem_instr_call(unsigned short instruction, unsigned char* text_out); // 2
extern void disassem_instr_skip_if_eq_immed(unsigned short instruction, unsigned char* text_out); // 3
extern void disassem_instr_skip_if_ne_immed(unsigned short instruction, unsigned char* text_out); // 4
extern void disassem_instr_skip_if_eq_reg(unsigned short instruction, unsigned char* text_out); // 5
extern void disassem_instr_load_immed(unsigned short instruction, unsigned char* text_out); // 6
extern void disassem_instr_add_immed(unsigned short instruction, unsigned char* text_out);  // 7
extern void disassem_instr_8_family(unsigned short instruction, unsigned char* text_out); // 8xxx is a special case.
extern void disassem_instr_skip_if_ne_reg(unsigned short instruction, unsigned char* text_out); // 9
extern void disassem_instr_load_i_reg(unsigned short instruction, unsigned char* text_out); // A
extern void disassem_instr_jump_offset(unsigned short instruction, unsigned char* text_out); // B
extern void disassem_instr_rand(unsigned short instruction, unsigned char* text_out); // C
extern void disassem_instr_display(unsigned short instruction, unsigned char* text_out); // D
extern void disassem_instr_e_family(unsigned short instruction, unsigned char* text_out); // E special
extern void disassem_instr_f_family(unsigned short instruction, unsigned char* text_out); // F special

extern void (*instr_ptr[16])(unsigned short);
extern void (*disassem_instr_ptr[16])(unsigned short, unsigned char*);
extern char* instr_text[16];

#endif