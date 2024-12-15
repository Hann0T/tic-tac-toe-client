#include <curses.h>
#include "includes/game.h"
#include "includes/menu.h"

char *menu_choises[] = {
    "Start",
    "Pause",
    "Exit",
};

game_status_t init_game_status() {
  WINDOW *menu = create_menu_window(10, 20);
  wrefresh(menu);
  keypad(menu, TRUE);

  bool in_menu = true;
  int options_size = sizeof(menu_choises) / sizeof(char *);
  int position = 0;

  curs_set(0); // hide cursor
  while (in_menu) {
    print_menu(menu, menu_choises, options_size, position);
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
      in_menu = false;
      break;
    default:
      break;
    }
  }
  curs_set(0); // show cursor
  delete_menu_window(menu);
  refresh();
  return STARTED;
}
