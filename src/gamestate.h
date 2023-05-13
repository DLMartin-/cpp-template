#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include <optional>
#include <variant>
#include <SDL.h>

struct Title {};
struct OverWorld {};
struct GameOver {};
struct ShuttingDown {};
struct Transition {
  unsigned elapsed_frames;
};

using GameState = std::variant<Title, OverWorld, GameOver, ShuttingDown, Transition>;

#endif

