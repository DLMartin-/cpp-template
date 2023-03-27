#ifndef MY_PROJ_INPUT_H
#define MY_PROJ_INPUT_H
#include <cstdint>
#include <array>

#include <SDL.h>

struct KeyboardController {
    enum struct Key {
        Action,
        Cancel,
        Up,
        Down,
        Left,
        Right
    };
    std::uint8_t const* state = SDL_GetKeyboardState(nullptr);
    std::array<std::uint8_t, 6> keycode_map{SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT};

    [[nodiscard]] bool is_key_down(Key key) const noexcept;
    [[nodiscard]] bool is_key_up(Key key) const noexcept;
};

#endif //MY_PROJ_INPUT_H
