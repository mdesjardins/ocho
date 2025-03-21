#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "core.h"

// memory.
unsigned char* mem; // [MEMORY_SIZE];

// registers and timers.
unsigned short pc_reg;
unsigned short i_reg;
unsigned short v_reg[NUM_REGISTERS];
unsigned char delay_timer;
unsigned char sound_timer;

// runs at 60Hz.
void timer_callback(int signum) {
    if (delay_timer != 0) {
        delay_timer--;
    }
    
    if (sound_timer != 0) {
        // beep.
        sound_timer--;
    }
}

// main initialization of the vm.
void init_core() {
    // clear memory.
    mem = malloc(MEMORY_SIZE);
    if (mem == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    memset(mem, 0, MEMORY_SIZE);

    // set up timers.
    delay_timer = 0;
    sound_timer = 0;
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timer_callback;
    sigaction(SIGALRM, &sa, NULL);

    struct itimerval timer;
    memset(&timer, 0, sizeof(timer));
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = DELAY_TIMER_PERIOD_USEC;
    timer.it_interval.tv_usec = 0;
    timer.it_interval.tv_usec = DELAY_TIMER_PERIOD_USEC;
    setitimer(ITIMER_REAL, &timer, NULL);
}