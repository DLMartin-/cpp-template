#include "title.h"
#include "shuttingdown.h"
#include "overworld.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<std::variant<OverWorld, ShuttingDown>> process_event(Title& title, SDL_Event const& event) {
  if(event.type != SDL_EVENT_KEY_DOWN)
    return std::nullopt;

  if(event.key.repeat != 0) {
    return std::nullopt;
  }
 
  if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
    return OverWorld{};

  if(event.key.keysym.scancode == SDL_SCANCODE_Q)
    return ShuttingDown{};

  return std::nullopt;
}

void update_tic(Title& title) { 
  fmt::print(fg(fmt::color::coral) | fmt::emphasis::bold,
             "Title State update (NEW)\n");
}
