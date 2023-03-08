#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <sstream>

#include "pomodoro.h"

void Pomodoro::Start() {
    Countdown();
}

void Pomodoro::Countdown() {
    int remaining_duration = 0;
    std::string cycle_message;

    switch (state_tracker->GetState()) {
        case PomodoroState::Idle:
        case PomodoroState::ShortBreak:
        case PomodoroState::LongBreak:
            state_tracker->SetWorkState();

            cycle_message = "State: Work";
            remaining_duration = pomodoro_config->work_ms;
            break;

        case PomodoroState::Work:
            PomodoroState new_state = state_tracker->SetBreakState();
            
            // Determine if we need a long break or not.
            if (new_state == PomodoroState::LongBreak) {
                cycle_message = "State: Long Break";
                remaining_duration = pomodoro_config->long_break_ms;
            } else {
                cycle_message = "State: Break";
                remaining_duration = pomodoro_config->break_ms;
            }
            break;
    }

    while (remaining_duration > 0) {
        system("clear");
        auto duration = FormatDuration(remaining_duration);
        
        std::cout << cycle_message << std::endl;
        std::cout << duration << std::endl;

        std::this_thread::sleep_for(pomodoro_config->GetTickDuration());
        remaining_duration -= 1000;
    }

    Countdown();
}

std::string Pomodoro::FormatDuration(int duration) {
    std::stringstream formatted_duration;
   
    auto duration_as_chrono = std::chrono::milliseconds(duration);
    auto minutes_remaining_as_chrono = duration_cast<std::chrono::minutes>(duration_as_chrono); 
    auto minutes_remaining = minutes_remaining_as_chrono.count();
    
    formatted_duration << std::setfill('0') << std::setw(2);
    formatted_duration << minutes_remaining << ":";   

    duration_as_chrono -= minutes_remaining_as_chrono;
    auto seconds_remaining = duration_cast<std::chrono::seconds>(duration_as_chrono).count();

    formatted_duration << std::setfill('0') << std::setw(2);
    formatted_duration << seconds_remaining;

    return formatted_duration.str();
}
