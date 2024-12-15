#include <curses.h>
#include "includes/menu.h"

WINDOW *create_menu_window(int win_lines, int win_cols) {
  WINDOW *menu = newwin(win_lines, win_cols, (LINES / 2) - (win_lines / 2),
                        (COLS / 2) - (win_cols / 2));
  box(menu, 0, 0);
  // wborder(menu, '|', '|', '-', '-', '+', '+', '+', '+');

  return menu;
}

void delete_menu_window(WINDOW *menu) {
  werase(menu);
  wborder(menu, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  clrtoeol();
  wrefresh(menu);
  delwin(menu);
}

void print_menu(WINDOW *menu, char *options[], int options_size,
                int option_selected_position) {
  int row = 2;
  int col = 2;

  for (int i = 0; i < options_size; i++) {
    if (i == option_selected_position) {
      wattron(menu, A_REVERSE);
      mvwprintw(menu, row, col, "%s", options[i]);
      wattroff(menu, A_REVERSE);
    } else {
      mvwprintw(menu, row, col, "%s", options[i]);
    }

    row += 1;
  }

  wrefresh(menu);
}
