#ifndef MENU_H
#define MENU_H

#include <curses.h>

typedef enum MenuChoice { START_GAME, EXIT_GAME } menu_choice_t;

typedef struct MenuOption {
  const char *label;
  menu_choice_t value;
} menu_option_t;

void print_menu(WINDOW *menu, menu_option_t options[], int options_size,
                int option_selected_position);
#endif
