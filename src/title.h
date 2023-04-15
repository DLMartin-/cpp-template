#ifndef TITLE_STATE_H_
#define TITLE_STATE_H_

#include <optional>
#include <variant>

#include <SDL.h>

struct ShuttingDown;
struct OverWorld;

struct Title {};

std::optional<std::variant<OverWorld, ShuttingDown>> process_event(Title& title, SDL_Event const& event);
void update_tic(Title& title);

#endif

