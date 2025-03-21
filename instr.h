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

extern void (*instr_ptr[16])(unsigned short);

#endif