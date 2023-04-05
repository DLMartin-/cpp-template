#ifndef MYPROJ_SCREENS_OVERWORLD_H_
#define MYPROJ_SCREENS_OVERWORLD_H_
#include <optional>
#include <SDL_events.h>

#include "transition.h"

struct OverworldScreen {};

std::optional<TransitionEvent> on_event(OverworldScreen& screen, SDL_KeyboardEvent const& event);
void update_tic(OverworldScreen& screen);
void draw(OverworldScreen const& screen);

#endif

