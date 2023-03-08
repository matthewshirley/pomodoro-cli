#ifndef POMODOROCONFIG_H
#define POMODOROCONFIG_H

#include <chrono>

using namespace std::chrono_literals;
using namespace std::chrono;

class PomodoroConfig {
    public:
        int work_ms;
        int break_ms;
        int long_break_ms; 

        PomodoroConfig(int work_minutes, int break_minutes, int long_break_minutes) {
            this->work_ms = work_minutes * 60 * 1000;
            this->break_ms = break_minutes * 60 * 1000;
            this->long_break_ms = long_break_minutes * 60 * 1000;

            this->tick_duration = 1s;
        }

        seconds GetTickDuration();

    private:
        seconds tick_duration;
};

#endif
