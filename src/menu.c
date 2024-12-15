#include "includes/menu.h"
#include <curses.h>

void print_menu(WINDOW *menu, menu_option_t options[], int options_size,
                int option_selected_position) {
  int row = 2;
  int col = 2;

  for (int i = 0; i < options_size; i++) {
    if (i == option_selected_position) {
      wattron(menu, A_REVERSE);
      mvwprintw(menu, row, col, "%s", options[i].label);
      wattroff(menu, A_REVERSE);
    } else {
      mvwprintw(menu, row, col, "%s", options[i].label);
    }

    row += 1;
  }

  wrefresh(menu);
}
