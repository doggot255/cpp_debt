#include "Timer.h"

void Timer::start()
{
    timer_start = std::chrono::system_clock::now();
}

double Timer::elapsed_miliseconds()
{
    timer_end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(timer_end - timer_start).count();
}
