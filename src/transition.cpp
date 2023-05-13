#include "transition.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<GameState> process_event(Transition& transition, SDL_Event const& event) {
  return std::nullopt;
}

std::optional<GameState> update_tic(Transition& transition) { 
  fmt::print(fg(fmt::color::green) | fmt::emphasis::bold,
             "Transition frame count: {}\n", transition.elapsed_frames);

  transition.elapsed_frames++;

  if(transition.elapsed_frames > 128) 
    return OverWorld{};

  return std::nullopt;
}

void display(Transition const& transition, SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

