#ifndef TITLE_STATE_H_
#define TITLE_STATE_H_

#include <optional>
#include <variant>

#include <SDL.h>
#include "gamestate.h"

std::optional<GameState> process_event(Title& title, SDL_Event const& event);
std::optional<GameState> update_tic(Title& title);
void display(Title const& overworld, SDL_Renderer* renderer);

#endif

