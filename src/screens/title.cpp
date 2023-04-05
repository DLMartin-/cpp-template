#include "title.h"

#include <fmt/color.h>
#include <fmt/core.h>

std::optional<TransitionEvent> on_event(TitleScreen &screen, SDL_KeyboardEvent const& event) {
    fmt::print("TitleScreen::on_event!\n");
    if(event.keysym.scancode == SDL_SCANCODE_A) return TransitionToOverworld{};
    return std::nullopt;
}

void update_tic(TitleScreen &screen) {
    fmt::print("TitleScreen::update!\n");
}

void draw(const TitleScreen &screen) {

}

