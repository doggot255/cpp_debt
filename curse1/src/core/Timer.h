#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>

class Timer
{
    std::chrono::time_point<std::chrono::system_clock> timer_start;
    std::chrono::time_point<std::chrono::system_clock> timer_end;

public:
    void start();
    double elapsed_miliseconds();
};



#endif
