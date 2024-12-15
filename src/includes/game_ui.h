#ifndef GAME_UI_H
#define GAME_UI_H

#include "menu.h"
#include <curses.h>

WINDOW *draw_grid(int win_lines, int win_cols);
menu_choice_t prompt_start_menu();
void paint_cell(WINDOW *window, int position, char ch);

#endif
