/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 6 Sorting Algorithm analysis
*/
#ifndef TIMER_H
#define TIMER_H
#include <time.h>
#include <string>
//Timer class with basic start stop functionality to get the time elapsed as well as the 
//specific times at which timing started and ended

class Timer
{
    public:
        //constructor and destructor
        Timer();
        ~Timer();
        //basic methods to start/stop timing
        void startTimer();
        void stopTimer();
        //returns a float value of the seconds elapsed between stopping and starting
        float getSecondsElapsed();
        //resets time values for the timer
        void resetTimer();
        //returns the starting time and end time as strings
        std::string getStartTime();
        std::string getEndTime();

    private:
        //time objects to store stoping and starting times
        time_t startTime;
        time_t endTime;
        //also store starting and stop times but used to calculate time elapsed as a float
        clock_t startClock;
        clock_t endClock;
        //stores the time elapsed as a float value in seconds
        float timeElapsed;
        
};
#endif