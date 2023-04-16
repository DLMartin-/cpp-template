#ifndef GAME_OVER_STATE_H_
#define GAME_OVER_STATE_H_
#include <optional>
#include <SDL.h>

struct Title;
struct GameOver {};

std::optional<Title> process_event(GameOver& gameover, SDL_Event const& event);
void update_tic(GameOver& gameover);
void display(GameOver const& gameover, SDL_Renderer* renderer);

#endif

