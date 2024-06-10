//
// Created by eciuc on 6/10/2024.
//

#include "Stopwatch.h"

void Stopwatch::start_timing() {
    start_moment = high_resolution_clock::now();
}

high_resolution_clock::duration Stopwatch::elapsed_time() {
    return high_resolution_clock::now()-start_moment;
}
