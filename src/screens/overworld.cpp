#include "overworld.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<TransitionEvent> on_event(OverworldScreen &screen, SDL_KeyboardEvent const& event) {
    fmt::print("OverworldScreen::on_event!\n");
    if(event.keysym.scancode == SDL_SCANCODE_S) return TransitionToTitle{};
    return std::nullopt;
}

void update_tic(OverworldScreen &screen) {
    fmt::print("OverworldScreen::update!\n");
}

void draw(const OverworldScreen &screen) {

}

