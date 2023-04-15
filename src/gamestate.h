#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "title.h"
#include "shuttingdown.h"
#include "overworld.h"
#include "gameover.h"

#include <optional>
#include <variant>
#include <SDL.h>

using GameState = std::variant<Title, OverWorld, GameOver, ShuttingDown>;

std::optional<GameState> dispatch_event(GameState& gamestate, SDL_Event const& event);
std::optional<GameState> run_simulation(GameState& gamestate);

#endif

