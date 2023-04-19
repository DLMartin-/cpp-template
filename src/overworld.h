#ifndef OVERWORLD_STATE_H_
#define OVERWORLD_STATE_H_
#include <optional>
#include <SDL.h>
#include "gamestate.h"

std::optional<GameState> process_event(OverWorld& overworld, SDL_Event const& event);
std::optional<GameState> update_tic(OverWorld& overworld);
void display(OverWorld const& overworld, SDL_Renderer* renderer);
#endif

