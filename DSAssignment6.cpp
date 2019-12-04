#include <iostream>
#include <string>
#include "Timer.h"
#include <iomanip>
#include <fstream>
#include <math.h>

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

void copyArray(double* firstArray,double* secondArray,int length)
{
    for(int i =0; i <length;i++)
    {
        secondArray[i] = firstArray[i];
    }
}



int main(int arc, char** argv)
{
    ifstream inputStream;
    if(!argv[1])
    {
        cout << "No text file name entered as argument to open, aborting" << endl;
        exit(1);
    }
    inputStream.open(argv[1]);
    if(!inputStream)
    {
        cout << "Failed to open file"<<endl;
        exit(1);
    }

    string fileIn;
    getline(inputStream,fileIn);
    //get the number of doubles to sort
    int length = std::stoi(fileIn);
    double *array = new double[length];
    double *secondArray = new double[length];
    copyArray(array,secondArray,length);
    Timer *timer = new Timer();

    //read in the data
    float inFloat;
    int index= 0;
    while(getline(inputStream,fileIn))
    {
        inFloat = std::stof(fileIn);
        array[index] = inFloat;
        index ++;
    }

    inputStream.close();

    //timing for bubblesort
    timer->resetTimer();
    timer->startTimer();
    bubbleSort(secondArray, length);
    timer->stopTimer();

    cout << "Time elapsed for bubble sort: " << std::setprecision(15) << std::showpoint << std::fixed;
    cout << timer->getSecondsElapsed() << " seconds" << endl;

    cout << "Beginning time: " << timer->getStartTime();
    cout << "End time: " << timer->getEndTime();

    //timing for insertion sort
    timer ->resetTimer();
    timer->startTimer();
    insertionSort(array,length);
    timer ->stopTimer();
 
    //to change format from scientific notaiton to decimal
    cout <<"Time elapsed for insertion sort: " <<std::setprecision(15)<<std::showpoint<<std::fixed;
    cout << timer->getSecondsElapsed() << " seconds"<<endl;
                
    cout << "Beginning time: " << timer->getStartTime();
    cout << "End time: " << timer->getEndTime();

    
    //////do fill file with new numbers

    // ofstream outputStream;
    // outputStream.open("toSort.txt");
    // srand(time(0));
    // outputStream << "40000\r\n";
    // for(int i =0;i<40000;++i)
    // {
    //     int toWrite = rand()%50000;
    //     outputStream << toWrite<<"\r\n";
    // }
    // cout << "File Filled"<<endl;
    // outputStream.close();

    delete array;
    delete timer;
    return 0;
}