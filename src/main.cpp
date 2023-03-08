#include <cstdlib>
#include <cxxopts.hpp>
#include <iostream>

#include "pomodoro.h"
#include "pomodoro_state.h"
#include "pomodoro_config.h"

int main(int argc, char *argv[]) {
    cxxopts::Options options("dog");
    
    options.add_options()
            ("w,work", "How long should each work cycle be?", cxxopts::value<int>()->default_value("25"))
            ("b,break", "How long should each break cycle be?", cxxopts::value<int>()->default_value("5"))
            ("l,long-break", "How long should each long break cycle be?", cxxopts::value<int>()->default_value("15"));

    cxxopts::ParseResult result;

    int work_minutes = 25;
    int break_minutes = 5;
    int long_break_minutes = 15;
   
    try {
        result = options.parse(argc, argv);

        if (result.count("work")) {
            work_minutes = result["work"].as<int>();
        }

        if (result.count("break")) {
            break_minutes = result["break"].as<int>();
        }

        if (result.count("long-break")) {
            long_break_minutes = result["long-break"].as<int>();
        }
    } catch (const cxxopts::exceptions::parsing &e) {
        std::cerr << "pomodoro: " << e.what() << "\n";
        std::cerr << "usage: pomodoro [options] \n";
        
        return EXIT_FAILURE;
    }

    PomodoroConfig config = PomodoroConfig(work_minutes, break_minutes, long_break_minutes);
    PomodoroStateTracker tracker;

    Pomodoro pomodoro(&tracker, &config);
    pomodoro.Start();

    return EXIT_SUCCESS;
}
