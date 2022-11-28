#include <iostream>
#include <string>
#include "Game/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

Game *game = NULL;

int main(int argc, char* args[] )
{
  game = new Game();

  game->init("Ramburger", SCREEN_WIDTH, SCREEN_HEIGHT);
  game->setup();

  while (true && game->running())
  {
    game->frameStart();
    game->handleEvents();
    game->update();
    game->render();
    game->frameEnd();
  }

  game->clean();
  return 0;
}