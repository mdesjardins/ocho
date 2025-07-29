
#include <stdio.h>
#include <stdarg.h>
#include "core.h"
#include "instr.h"
#include "debug.h"

FILE* log_file = NULL;

void dump_memory_to_console() {
    for (int i=0; i<MEMORY_SIZE; i++) {
        if ((i % 32) == 0) {
            log("\n%03x-%03x: ", i, i+31);
        }
        log("%02x ", *(mem+i)); 
    }
}

void trace() {
    unsigned short* instruction;
    instruction = mem + pc_reg;
    if (*instruction != 0) {
        int i;
        for (i=0; i<NUM_REGISTERS/2; i++) {
            log("v%02x:%04x ", i, v_reg[i]);
        }
        log("pc:%x", pc_reg);

        unsigned short* instruction;
        instruction = mem + pc_reg;

        unsigned char msb = (0xF000 & *instruction) >> 12;
        char instr_text[16];
        (*disassem_instr_ptr[msb])(*instruction, instr_text);

        log("  %04x  %s\n\r", *instruction, instr_text);

        for (; i<NUM_REGISTERS; i++) {
            log("v%02x:%04x ", i, v_reg[i]);
        }
        log("i: %x\n\r", i_reg);
    }
}

/*
 * Log a message to the log file.
 * If the log file is not set, use stderr.
 */
void log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    if (log_file == NULL) {
        log_file = stderr;
    }
    vfprintf(log_file, format, args);
    va_end(args);
}