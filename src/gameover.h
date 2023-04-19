#ifndef GAME_OVER_STATE_H_
#define GAME_OVER_STATE_H_
#include <optional>
#include <SDL.h>
#include "gamestate.h"

std::optional<GameState> process_event(GameOver& gameover, SDL_Event const& event);
std::optional<GameState> update_tic(GameOver& gameover);
void display(GameOver const& gameover, SDL_Renderer* renderer);

#endif

