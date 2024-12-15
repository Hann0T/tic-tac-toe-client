#include <curses.h>

WINDOW *create_window(int win_lines, int win_cols) {
  WINDOW *menu = newwin(win_lines, win_cols, (LINES / 2) - (win_lines / 2),
                        (COLS / 2) - (win_cols / 2));
  box(menu, 0, 0);
  // wborder(menu, '|', '|', '-', '-', '+', '+', '+', '+');

  return menu;
}

void delete_window(WINDOW *menu) {
  werase(menu);
  wborder(menu, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  clrtoeol();
  wrefresh(menu);
  delwin(menu);
}
