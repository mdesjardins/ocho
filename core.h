#ifndef __CORE_H__
#define __CORE_H__

#define MEMORY_SIZE 4096
#define PROGRAM_START_OFFSET 0x200
#define NUM_REGISTERS 16
#define DELAY_TIMER_HZ 60.0
#define DELAY_TIMER_PERIOD_USEC (100000.0/DELAY_TIMER_HZ)

extern unsigned char *mem;
extern unsigned short pc_reg;
extern unsigned short i_reg;
extern unsigned short v_reg[NUM_REGISTERS];

extern void init_core();

#endif /* __CORE_H__ */