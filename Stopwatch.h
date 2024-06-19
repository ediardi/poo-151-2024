//
// Created by eciuc on 6/10/2024.
//

#ifndef OOP_STOPWATCH_H
#define OOP_STOPWATCH_H

#include <chrono>
#include <string>
#include "GameStateError.h"

using namespace std::chrono;
class Stopwatch {
private:
    static inline high_resolution_clock::time_point start_moment;
    static inline bool isrunning=false;
    Stopwatch() = default;
    static void start_timing();
    static high_resolution_clock::duration elapsed_time();
public:
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;
    static Stopwatch& get_app() {
        static Stopwatch stopwatch;
        return stopwatch;
    }
    static void discard_double_action(){
        if(isrunning)
        {
            auto interval=elapsed_time();
            if(interval < 0.2s)
            {
                start_timing();
                double dur= static_cast<double>(interval.count())/1e9;
                throw DoubleClick("Action detected " + std::to_string (dur) + "s after previous can_be_captured, discarding input");
            }
        }
        start_timing();
        isrunning = true;
    }
};


#endif //OOP_STOPWATCH_H
