#include "appmain.h"
#include <SDL3/SDL.h>
#include <fmt/color.h>
#include <fmt/core.h>

int main(int const argc, char const *const argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "There has been an error while initializing SDL!");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Error: {}",
               SDL_GetError());
    return -1;
  }

  return app_main();
}
