#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <string>

class Timer
{
    public:
        
        Timer();
        ~Timer();
        void startTimer();
        void stopTimer();
        float getSecondsElapsed();
        void resetTimer();
        std::string getStartTime();
        std::string getEndTime();

    private:
        time_t startTime;
        time_t endTime;
        clock_t startClock;
        clock_t endClock;
        float timeElapsed;
        
};
#endif