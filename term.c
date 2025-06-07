#include "term.h"

void init_term() {
  initscr();
  noecho();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);
}

void cleanup_term() {
  endwin();
}  