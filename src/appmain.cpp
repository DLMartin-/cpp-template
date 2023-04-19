#include <optional>
#include <variant>
#include <fmt/color.h>
#include <fmt/core.h>

#include <SDL.h>
#include "gamedata.h"
#include "gamestate.h"

#include "gameover.h"
#include "title.h"
#include "overworld.h"

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

std::optional<GameState> dispatch_event(GameState& gamestate, SDL_Event const& event);
std::optional<GameState> run_simulation(GameState& gamestate);

void display(GameState const& gamestate, SDL_Renderer* renderer);

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

    if(auto const maybe_new_state = run_simulation(current_state); maybe_new_state.has_value())
      current_state = maybe_new_state.value();
      
    display(current_state, renderer);
  }

  return 0;
}

std::optional<GameState> dispatch_event(GameState& gamestate, SDL_Event const& event) {
  return std::visit([event](auto&& s) -> std::optional<GameState> {
      using T = std::decay_t<decltype(s)>;

      if constexpr(std::is_same_v<T, ShuttingDown>) return std::nullopt;
      else return process_event(s, event);

    }, gamestate);
}

std::optional<GameState> run_simulation(GameState& gamestate) {
  return std::visit([](auto&& s) -> std::optional<GameState> {
      using T = std::decay_t<decltype(s)>;

      if constexpr(std::is_same_v<T, ShuttingDown>) return std::nullopt;
      else return update_tic(s);

    }, gamestate);
}

void display(GameState const& gamestate, SDL_Renderer* renderer) {
  std::visit([renderer](auto&& s) { 
      using T = std::decay_t<decltype(s)>;

      if constexpr(!std::is_same_v<T, ShuttingDown>)
        display(s, renderer);

    }, gamestate);

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

