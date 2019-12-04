#include "Timer.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

Timer::Timer(){}
Timer::~Timer(){}

void Timer::startTimer()
{
    time(&startTime);
    startClock = clock();
}
void Timer::stopTimer()
{
    time(&endTime);
    endClock = clock();
}
double Timer::getSecondsElapsed()
{
    double elapsed;
    elapsed = float(endClock-startClock)/CLOCKS_PER_SEC;
    return elapsed;
}
void Timer::resetTimer()
{
    timeElapsed =0;
}
string Timer::getStartTime()
{
    return ctime(&startTime);
}
string Timer::getEndTime()
{
    return ctime(&endTime);
}
