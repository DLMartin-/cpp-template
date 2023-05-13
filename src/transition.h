#ifndef TRANSITION_STATE_H_
#define TRANSITION_STATE_H_

#include <optional>
#include <variant>

#include <SDL.h>
#include "gamestate.h"

std::optional<GameState> process_event(Transition& title, SDL_Event const& event);
std::optional<GameState> update_tic(Transition& title);
void display(Transition const& overworld, SDL_Renderer* renderer);

#endif

