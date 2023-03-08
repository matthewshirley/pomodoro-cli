#include "pomodoro_state.h"

PomodoroState PomodoroStateTracker::GetState() {
    return _current_state;
}

PomodoroState PomodoroStateTracker::SetWorkState() {
    IncrementCycle();
    
    _current_state = PomodoroState::Work;
    return _current_state;
}

PomodoroState PomodoroStateTracker::SetBreakState() {
    if (_current_cycle >= 0 && _current_cycle < WORK_CYCLES_BEFORE_LONG_BREAK) {
        _current_state = PomodoroState::ShortBreak;
    } else if (_current_cycle >= WORK_CYCLES_BEFORE_LONG_BREAK) {
        _current_state = PomodoroState::LongBreak;
    } else {
        _current_state = PomodoroState::Idle;
    }

    return _current_state;
}

void PomodoroStateTracker::IncrementCycle() {
    if (_current_cycle < WORK_CYCLES_BEFORE_LONG_BREAK) {
        _current_cycle += 1;
    } else {
        _current_cycle = 0;
    }
}


