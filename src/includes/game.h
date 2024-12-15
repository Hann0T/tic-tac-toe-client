#ifndef GAME_H
#define GAME_H

#include "menu.h"

typedef enum GameStatus { RUNNING, CLOSED, STOPPED } game_status_t;

void process_move();

#endif
