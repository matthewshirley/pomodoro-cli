#ifndef POMODOROSTATE_H
#define POMODOROSTATE_H

const int WORK_CYCLES_BEFORE_LONG_BREAK = 2;

enum class PomodoroState {Idle, ShortBreak, LongBreak, Work};

class PomodoroStateTracker {
    int _current_cycle;
    PomodoroState _current_state;

    public:
        PomodoroStateTracker() {
            _current_state = PomodoroState::Idle;
            _current_cycle = 0;
        }
        
        PomodoroState GetState();
        PomodoroState SetWorkState();
        PomodoroState SetBreakState();

    private:
        void IncrementCycle();
};

#endif
