#include "pomodoro_config.h"

std::chrono::seconds PomodoroConfig::GetTickDuration() {
    return tick_duration;
}
