#include "gamestate.h"

std::optional<GameState> dispatch_event(GameState& gamestate, SDL_Event const& event) {
  return std::visit([event](auto&& s) -> std::optional<GameState> {
      using T = std::decay_t<decltype(s)>;

      if constexpr(std::is_same_v<T, ShuttingDown>) return std::nullopt;
      else if constexpr(std::is_same_v<T, Title>) {
        if(auto maybe = process_event(s, event); maybe.has_value()) {
          return std::visit([](auto&& s) -> GameState { return s; }, maybe.value());
        }
        return std::nullopt;
      } else {
        return process_event(s, event);
      }
    }, gamestate);
}

std::optional<GameState> run_simulation(GameState& gamestate) {
  return std::visit([](auto&& s) -> std::optional<GameState> {
      using T = std::decay_t<decltype(s)>;

      if constexpr(std::is_same_v<T, ShuttingDown>) return std::nullopt;
      else if constexpr(std::is_same_v<T, Title> || std::is_same_v<T, OverWorld> || std::is_same_v<T, GameOver>) {
        update_tic(s);
        return std::nullopt;
      } else {
        return update_tic(s);
      }
    }, gamestate);
}

