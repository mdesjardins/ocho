#ifndef __TERM_H__
#define __TERM_H__

#include <curses.h>
#include <panel.h>
#include <menu.h>
#include <ncurses.h>

void init_term();
void cleanup_term();
int key_pressed(unsigned char key);
void set_pixel(unsigned char x, unsigned char y, unsigned char value);

#endif