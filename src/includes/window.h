#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>

WINDOW *create_window(int win_lines, int win_cols);
void delete_window(WINDOW *menu);

#endif
