#include <curses.h>
#include <locale.h>
#include <stdbool.h>

#include "includes/game.h"

int ESC = 0x1B;
int ENTER = 0x0A;

int main() {
  char *locale = setlocale(LC_ALL, "en_US.UTF-8");
  int ch = 0;

  WINDOW *main_win = initscr();
  clear();
  noecho();
  raw();

  game_status_t game_status = init_game_status();

  if (game_status == STARTED) {
    printw("game started\n");
    getch();
  }


  // while (game_status == STARTED) {
  //   printw("Waiting for input\n");
  //   ch = getch();

  //  if (ch == ESC) {
  //    printw("Game is ending\n");
  //    refresh();
  //    game_status = ENDED;
  //  }
  //}

  endwin();
  return 0;
}
