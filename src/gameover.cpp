#include "gameover.h"
#include "title.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<Title> process_event(GameOver& gameover, SDL_Event const& event) {
  if(event.type != SDL_EVENT_KEY_DOWN)
    return std::nullopt;

  if(event.key.repeat != 0) {
    return std::nullopt;
  }

  if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
    return Title{};

  return std::nullopt;
}

void update_tic(GameOver& gameover) {
  fmt::print(fg(fmt::color::blanched_almond) | fmt::emphasis::bold,
             "GameOver State update (NEW!!!!!!!!!!)\n");
}

