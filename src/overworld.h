#ifndef OVERWORLD_STATE_H_
#define OVERWORLD_STATE_H_
#include <optional>
#include <SDL.h>

struct GameOver;
struct OverWorld {};


std::optional<GameOver> process_event(OverWorld& overworld, SDL_Event const& event);
void update_tic(OverWorld& overworld);
void display(OverWorld const& overworld, SDL_Renderer* renderer);
#endif

