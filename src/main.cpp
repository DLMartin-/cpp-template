#include <SDL3/SDL.h>
#include "appmain.h"

int main (int const argc, char const * const argv[])
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) return -1;

  return app_main();
}

