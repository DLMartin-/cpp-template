#include "overworld.h"
#include "gameover.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<GameOver> process_event(OverWorld& overworld, SDL_Event const& event) {
  if(event.type != SDL_EVENT_KEY_DOWN)
    return std::nullopt;

  if(event.key.repeat != 0) {
    return std::nullopt;
  }

  if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
    return GameOver{};

  return std::nullopt;
}

void update_tic(OverWorld& overworld) {
  fmt::print(fg(fmt::color::coral) | fmt::emphasis::bold,
             "OverWorld State update (NEW!!!)\n");
}

void display(OverWorld const& overworld, SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 225, 25, SDL_ALPHA_OPAQUE);
}
