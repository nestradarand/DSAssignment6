/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 6 Sorting Algorithm analysis
*/
#include "Timer.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//constructor/destructor
Timer::Timer(){timeElapsed =0.0;}
Timer::~Timer(){}

//starts the time and stores an instance of the start time
void Timer::startTimer()
{
    time(&startTime);
    startClock = clock();
}
//stops the timer and stores an instance of the end time
void Timer::stopTimer()
{
    time(&endTime);
    endClock = clock();
}
//returns the seconds elapsed between start and stop times
float Timer::getSecondsElapsed()
{
    timeElapsed = float(endClock-startClock)/CLOCKS_PER_SEC;
    return timeElapsed;
}
//resets elapsed time to zero
void Timer::resetTimer()
{
    timeElapsed =0.00;
}
//returns the time the timer started as a string
string Timer::getStartTime()
{
    return ctime(&startTime);
}
//returns the time the timer stopped as a string
string Timer::getEndTime()
{
    return ctime(&endTime);
}
