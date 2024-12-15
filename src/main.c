#include <curses.h>
#include <locale.h>
#include <stdbool.h>

#include "includes/game.h"
#include "includes/game_ui.h"

int main() {
  char *locale = setlocale(LC_ALL, "en_US.UTF-8");
  WINDOW *main_win = initscr();
  game_status_t game_status;
  int ch = 0;

  clear();
  noecho();
  raw();

  menu_choice_t choice = prompt_start_menu();

  if (choice == EXIT_GAME) {
    printw("EXITTT game\n");
    getch();
    endwin();
    return 0;
  }

  if (choice == START_GAME) {
    game_status = RUNNING;
  }

  WINDOW *grid_win = draw_grid(15, 30);

  wrefresh(grid_win);
  keypad(grid_win, TRUE);
  printw("Waiting for input\n");
  refresh();

  // hardcoded
  int cursor_position = 0;
  int prev_cursor_position = 0;
  int min_position = 0;
  int max_position = 8;

  curs_set(0); // hide cursor
  paint_cell(grid_win, min_position, '#');
  while (game_status != CLOSED) {
    paint_cell(grid_win, prev_cursor_position, ' ');
    ch = wgetch(grid_win);
    switch (ch) {
    case KEY_UP:
    case 'k':
      if (cursor_position > min_position) {
        prev_cursor_position = cursor_position;
        cursor_position -= 1;
      }
      break;
    case KEY_DOWN:
    case 'j':
      if (cursor_position < max_position) {
        prev_cursor_position = cursor_position;
        cursor_position += 1;
      }
      break;
    case 0x1B: // ESC
    case 'q':
      printw("Game CLOSED\n");
      refresh();
      getch();
      game_status = CLOSED;
      break;
    case 0x0A: // ENTER
      // paint_cell(grid_win, cursor_position, 'x');
      // continue;
      break;
    default:
      break;
    }

    paint_cell(grid_win, cursor_position, '#');
  }
  curs_set(1); // show cursor

  endwin();
  return 0;
}
