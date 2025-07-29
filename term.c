#include <signal.h>
#include "term.h"


int _kbhit(void) {
  int ch = getch();
  if (ch != ERR) {
    ungetch(ch);
    return 1;
  } else {
    return 0;
  }
}

void init_term() {
  initscr();
  noecho();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);
}

void cleanup_term() {
  curs_set(1);
  clear();
  endwin();
}  

void set_pixel(unsigned char x, unsigned char y, unsigned char value) {
  mvaddch(y, x, value ? 'X' : ' ');
}

int key_pressed(unsigned char key) {
  if (_kbhit()) {
    int ch = getch();
    if (ch == ERR) {
      return 0;
    }
    if (ch == 3) {
      raise(SIGINT);
    }
    return ch == key;
  }
  return 0;
}