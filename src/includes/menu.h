#ifndef MENU_H
#define MENU_H

#include <curses.h>

WINDOW *create_menu_window(int win_lines, int win_cols);
void delete_menu_window(WINDOW *menu);
void print_menu(WINDOW *menu, char *options[], int options_size,
                int option_selected_position);
#endif
