#ifndef MYPROJ_SCREENS_TITLE_H_
#define MYPROJ_SCREENS_TITLE_H_
#include <optional>
#include <SDL_events.h>

#include "transition.h"

struct TitleScreen {};

std::optional<TransitionEvent> on_event(TitleScreen& screen, SDL_KeyboardEvent const& event);
void update_tic(TitleScreen& screen);
void draw(TitleScreen const& screen);

#endif

