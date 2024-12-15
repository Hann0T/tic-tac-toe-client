#include "includes/game_ui.h"
#include "includes/menu.h"
#include "includes/window.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

menu_option_t menu_choices[] = {
    {.label = "Start", .value = START_GAME},
    {.label = "Exit", .value = EXIT_GAME},
};

menu_choice_t prompt_start_menu() {
  WINDOW *menu = create_window(10, 20);
  if (menu == NULL) {
    printf("Error trying to create the menu window\n");
    exit(EXIT_FAILURE);
  }

  wrefresh(menu);
  keypad(menu, TRUE);

  bool in_menu = true;
  int options_size = sizeof(menu_choices) / sizeof(menu_option_t);
  int position = 0;
  menu_choice_t choice = EXIT_GAME; // default to exit

  curs_set(0); // hide cursor
  while (in_menu) {
    print_menu(menu, menu_choices, options_size, position);
    int ch = wgetch(menu);

    switch (ch) {
    case KEY_UP:
    case 'k':
      position -= position > 0 ? 1 : 0;
      break;
    case KEY_DOWN:
    case 'j':
      position += position < (options_size - 1) ? 1 : 0;
      break;
    case 0x1B: // ESC
    case 'q':
      choice = EXIT_GAME;
      in_menu = false;
      break;
    case 0x0A: // ENTER
      if (strcmp(menu_choices[position].label, "Start") == 0) {
        choice = START_GAME;
      }
      if (strcmp(menu_choices[position].label, "Exit") == 0) {
        choice = EXIT_GAME;
      }
      in_menu = false;
      break;
    default:
      break;
    }
  }

  curs_set(1); // show cursor
  delete_window(menu);
  refresh();

  return choice;
}

void paint_cell(WINDOW *window, int position, char ch) {
  if (position < 0 || position > 8)
    return;

  int x, y = 0;
  getmaxyx(window, y, x);
  int cell_width = x / 3;
  int cell_height = y / 3;

  switch (position) {
  // first row
  case 0:
    mvwaddch(window, cell_height / 2, cell_width / 2, ch);
    break;
  case 1:
    mvwaddch(window, cell_height / 2, cell_width + (cell_width / 2), ch);
    break;
  case 2:
    mvwaddch(window, cell_height / 2, (cell_width * 2) + (cell_width / 2), ch);
    break;
  // second row
  case 3:
    mvwaddch(window, cell_height + (cell_height / 2), cell_width / 2, ch);
    break;
  case 4:
    mvwaddch(window, cell_height + (cell_height / 2),
             cell_width + (cell_width / 2), ch);
    break;
  case 5:
    mvwaddch(window, cell_height + (cell_height / 2),
             (cell_width * 2) + (cell_width / 2), ch);
    break;
  // third row
  case 6:
    mvwaddch(window, cell_height * 2 + (cell_height / 2), cell_width / 2, ch);
    break;
  case 7:
    mvwaddch(window, cell_height * 2 + (cell_height / 2),
             cell_width + (cell_width / 2), ch);
    break;
  case 8:
    mvwaddch(window, cell_height * 2 + (cell_height / 2),
             (cell_width * 2) + (cell_width / 2), ch);
    break;
  default:
    break;
  }

  wrefresh(window);
}

WINDOW *draw_grid(int win_lines, int win_cols) {
  WINDOW *window = create_window(win_lines, win_cols);
  if (window == NULL) {
    printf("Error trying to create the menu window\n");
    exit(EXIT_FAILURE);
  }

  int y = 0;
  int x = 0;

  // draw 1st col
  y = win_cols * 1 / 3;
  for (int x = 0; x < win_lines; x++) {
    mvwaddch(window, x, y, ACS_VLINE);
  }
  wrefresh(window);

  // draw 2nd col
  y = win_cols * 2 / 3;
  for (int x = 0; x < win_lines; x++) {
    mvwaddch(window, x, y, ACS_VLINE);
  }
  wrefresh(window);

  // draw 1st row
  x = win_lines * 1 / 3;
  for (int y = 0; y < win_cols; y++) {
    mvwaddch(window, x, y, ACS_HLINE);
  }
  wrefresh(window);

  // draw 2nd row
  x = win_lines * 2 / 3;
  for (int y = 0; y < win_cols; y++) {
    mvwaddch(window, x, y, ACS_HLINE);
  }
  wrefresh(window);

  // paint_cell(window, 0, 'x');
  // paint_cell(window, 1, 'x');
  // paint_cell(window, 2, 'o');
  // paint_cell(window, 3, 'x');
  // paint_cell(window, 4, 'o');
  // paint_cell(window, 5, 'x');
  // paint_cell(window, 6, 'x');
  // paint_cell(window, 7, 'o');
  // paint_cell(window, 8, 'x');

  return window;
}
