#include <iostream>
#include <string>
#include "Timer.h"
#include <iomanip>

using namespace std;

void bubbleSort(double* theArray,int length)
{
    for(int i =0; i<length;i++)
    {
        double temp = 0;
        for(int j =0; j<(length-1);j++)
        {
            if(theArray[j]> theArray[j+1])
            {
                temp = theArray[j+1];
                theArray[j+1] = theArray[j];
                theArray[j] = temp;
            }
        }
    }
}

void selectionSort(double* theArray,int length)
{
    int i,j,minIndex,tmp;
    for(i=0;i<(length-1);i++)
    {
        minIndex = i;
        for(j = (i+1);j<length;j++)
        {
            if(theArray[j]<theArray[minIndex])
                minIndex = j;
        }
        if(minIndex!= i)
        {
            tmp = theArray[i];
            theArray[i] = theArray[minIndex];
            theArray[minIndex] = tmp;
        }
    }
}

void insertionSort(double* theArray,int length)
{
    for(int j=1;j<length;++j)
    {
        double temp = theArray[j];
        int k = j;
        while(k>0 && theArray[k-1] >=temp)
        {
            theArray[k] = theArray[k-1];
            --k;
        }
        theArray[k] = temp;
    }
}

//need quick sort and another algorithm from the book possibly
void quickSort(double* theArray,int length)
{
    
}




int main(int arc, char** argv)
{
    Timer *timer = new Timer();
    double array [] = {3.0,1.0,2.0,5.0,7.0,8.0,2.3,2.4,2.5,3.77};
    int length = 10;
    timer->startTimer();
    insertionSort(array,length);
    timer ->stopTimer();
 
    //to change format from scientific notaiton to decimal
    cout <<"Time elapsed: " <<std::setprecision(15)<<std::showpoint<<std::fixed;
    cout << timer->getSecondsElapsed() << " seconds"<<endl;
                
    cout << "Beginning time: " << timer->getStartTime();
    cout << "End time: " << timer->getEndTime();
    return 0;
}