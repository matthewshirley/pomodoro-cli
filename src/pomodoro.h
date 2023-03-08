#ifndef POMODORO_H
#define POMODORO_H

#include <iostream>

#include "pomodoro_state.h"
#include "pomodoro_config.h"

class Pomodoro {
    PomodoroStateTracker* state_tracker;
    PomodoroConfig* pomodoro_config;

    public:
        Pomodoro(PomodoroStateTracker* state_tracker, PomodoroConfig* pomodoro_config) {
            this->state_tracker = state_tracker;
            this->pomodoro_config = pomodoro_config;
        }

        void Start();

    private:
        void Countdown();
        std::string FormatDuration(int remaining_duration);
};

#endif
