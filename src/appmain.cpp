#include <SDL.h>
#include <fmt/color.h>
#include <fmt/core.h>

[[nodiscard]] int app_main() noexcept {
  SDL_Window *window = SDL_CreateWindow("My App", 480, 300, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr, 0);

  if (window == nullptr || renderer == nullptr) {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "There has been an error creating a window or renderer!\n");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Error: {}",
               SDL_GetError());
    return -1;
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  SDL_Event event;
  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  return 0;
}
