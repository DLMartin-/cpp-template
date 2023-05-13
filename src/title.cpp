#include "title.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<GameState> process_event(Title& title, SDL_Event const& event) {
  if(event.type != SDL_EVENT_KEY_DOWN)
    return std::nullopt;

  if(event.key.repeat != 0) {
    return std::nullopt;
  }
 
  if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
    return Transition{};

  if(event.key.keysym.scancode == SDL_SCANCODE_Q)
    return ShuttingDown{};

  return std::nullopt;
}

std::optional<GameState> update_tic(Title& title) { 
  fmt::print(fg(fmt::color::coral) | fmt::emphasis::bold,
             "Title State update (NEW)\n");
  return std::nullopt;
}

void display(Title const& overworld, SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
}

