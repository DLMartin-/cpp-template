#ifndef MY_PROJ_SCREENS_TRANSITION_H_
#define MY_PROJ_SCREENS_TRANSITION_H_
#include <variant>

struct TransitionToTitle{};
struct TransitionToOverworld{};

using TransitionEvent = std::variant<TransitionToTitle, TransitionToOverworld>;

#endif

