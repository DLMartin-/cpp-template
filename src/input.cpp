#include "input.h"

[[nodiscard]] bool KeyboardController::is_key_down(Key key) const noexcept {
    auto const scancode = keycode_map[static_cast<std::uint8_t>(key)];
    return state[scancode] != 0;
}

[[nodiscard]] bool KeyboardController::is_key_up(Key key) const noexcept {
    auto const scancode = keycode_map[static_cast<std::uint8_t>(key)];
    return state[scancode] == 0;
}
