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


int key_pressed(unsigned char key) {
  if (_kbhit()) {
    int ch = getch();
    if (ch == ERR) {
      return 0;
    }
    return ch == key;
  }
  return 0;
}