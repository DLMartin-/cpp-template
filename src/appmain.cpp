#include <optional>
#include <variant>
#include <fmt/color.h>
#include <fmt/core.h>

#include <SDL.h>
#include "gamedata.h"
#include "gamestate.h"

// Cute trick to use with structured bindings!
//  A hidden SdlWindowContext variable will be created, and go out of scope
//  like a normal variable. So you can use it as a way to manage lifetimes
//  of SDL_Window and SDL_Renderer.
struct SdlWindowContext {
  SDL_Window *window;
  SDL_Renderer *renderer;

  ~SdlWindowContext() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
  }
};

[[nodiscard]] SdlWindowContext
create_window_and_renderer(std::string_view title, int width, int height,
                           int window_flags, int renderer_flags) noexcept {
  auto window = SDL_CreateWindow(title.data(), width, height, window_flags);
  auto renderer = SDL_CreateRenderer(window, nullptr, renderer_flags);
  return SdlWindowContext{window, renderer};
}

[[nodiscard]] int app_main() noexcept {
  auto [window, renderer] =
      create_window_and_renderer("Template", 400, 400, 0, 0);
  if (window == nullptr || renderer == nullptr) {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "There has been an error creating a window or renderer!\n");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Error: {}",
               SDL_GetError());
    return -1;
  }

  GameState current_state;
  GameData game_data;
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  SDL_Event event;
  while (std::holds_alternative<ShuttingDown>(current_state) == false) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        current_state = ShuttingDown{};
        break;
      }

      auto const maybe_new_state = dispatch_event(current_state, event);
      if(maybe_new_state.has_value())
        current_state = maybe_new_state.value();
    }
    
    if(std::holds_alternative<ShuttingDown>(current_state)) break;

    auto const maybe_new_state = run_simulation(current_state);
    if(maybe_new_state.has_value())
      current_state = maybe_new_state.value();
      

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}

