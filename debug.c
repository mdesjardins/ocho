
#include <stdio.h>
#include "core.h"

void dump_memory_to_console() {
    for (int i=0; i<MEMORY_SIZE; i++) {
        if ((i % 32) == 0) {
            printf("\n%03x-%03x: ", i, i+31);
        }
        printf("%02x ", *(mem+i)); 
    }
}
