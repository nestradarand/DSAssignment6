#include <iostream>
#include <string>
#include "Timer.h"
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

void bubbleSort(float* theArray,int length)
{
    for(int i =0; i<length;i++)
    {
        float temp = 0;
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

void selectionSort(float* theArray,int length)
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

void insertionSort(float* theArray,int length)
{
    for(int j=1;j<length;++j)
    {
        float temp = theArray[j];
        int k = j;
        while(k>0 && theArray[k-1] >=temp)
        {
            theArray[k] = theArray[k-1];
            --k;
        }
        theArray[k] = temp;
    }
}

void merge(float* array, int lpos, int mpos, int rpos)
{
    int n1 = mpos - lpos + 1;
    int n2 = rpos - mpos;

    float *L =  new float[n1];
    float *R = new float[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[lpos + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mpos + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    int s1pos = 0; // Initial index of first subarray
    int s2pos = 0; // Initial index of second subarray
    int overallPos = lpos; // Initial index of merged subarray
    while (s1pos< n1 && s2pos < n2)
    {
        if (L[s1pos] <= R[s2pos])
            array[overallPos++] = L[s1pos++];
        else
            array[overallPos++] = R[s2pos++];
    }
    while (s1pos < n1)
        array[overallPos++] = L[s1pos++];
    while (s2pos < n2)
        array[overallPos++] = R[s2pos++];
    
}
    //inspired by geeksforgeeks.org
void mergeSort(float *array, int lpos, int rpos)
{
    if (lpos < rpos)
    {
        int mpos = lpos + (rpos - lpos) / 2;
        // Sort first and second halves
        mergeSort(array, lpos, mpos);
        mergeSort(array, mpos + 1, rpos);

        merge(array, lpos, mpos, rpos);
    }
}

void copyArray(float *firstArray, float *secondArray, int length)
{
    for (int i = 0; i < 3; ++i)
    {
        secondArray[i] = firstArray[i];
    }
}

    int main(int arc, char **argv)
    {
        ifstream inputStream;
        if (!argv[1])
        {
            cout << "No text file name entered as argument to open, aborting" << endl;
            exit(1);
        }
        inputStream.open(argv[1]);
        if (!inputStream)
        {
            cout << "Failed to open file" << endl;
            exit(1);
        }

        string fileIn;
        getline(inputStream, fileIn);
        //get the number of floats to sort
        int length = std::stoi(fileIn);
        float *array = new float[length];
        float *secondArray = new float[length];
        float *thirdArray = new float[length];
        float *fourthArray = new float[length];
        Timer *timer = new Timer();

        //read in the data
        float inFloat;
        int index = 0;
        while (getline(inputStream, fileIn))
        {
            inFloat = std::stof(fileIn);
            array[index] = inFloat;
            index++;
        }
        copyArray(array, secondArray, length);
        copyArray(array,secondArray,length);
        copyArray(array,thirdArray,length);
        copyArray(array,fourthArray,length);

        inputStream.close();

        //timing for bubblesort
        system("read -p 'Press Enter to start bubble sort timing...' var");
        cout << "Sorting. . . "<<endl;
        timer->resetTimer();
        timer->startTimer();
        bubbleSort(secondArray, length);
        timer->stopTimer();
        cout << "---------" << endl;
        cout << "Time elapsed for bubble sort: " << std::setprecision(15) << std::showpoint << std::fixed;
        cout << timer->getSecondsElapsed() << " seconds" << endl;
        cout << "Beginning time: " << timer->getStartTime();
        cout << "End time: " << timer->getEndTime();


        //timing for insertion sort
        system("read -p 'Press Enter to start insertion sort timing...' var");
        cout << "Sorting. . . " << endl;
        timer ->resetTimer();
        timer->startTimer();
        insertionSort(thirdArray,length);
        timer ->stopTimer();
        //to change format from scientific notaiton to decimal
        cout << "---------" << endl;
        cout <<"Time elapsed for insertion sort: " <<std::setprecision(15)<<std::showpoint<<std::fixed;
        cout << timer->getSecondsElapsed() << " seconds"<<endl;

        cout << "Beginning time: " << timer->getStartTime();
        cout << "End time: " << timer->getEndTime();


        //to clock selection sorting
        system("read -p 'Press Enter to start selection sort timing...' var");
        cout << "Sorting. . . " << endl;
        timer->resetTimer();
        timer->startTimer();
        selectionSort(fourthArray, length);
        timer->stopTimer();
        cout << "---------" << endl;
        cout << "Time elapsed for selection sort: " << std::setprecision(15) << std::showpoint << std::fixed;
        cout << timer->getSecondsElapsed() << " seconds" << endl;
        cout << "Beginning time: " << timer->getStartTime();
        cout << "End time: " << timer->getEndTime();

        //testing merge sort
        system("read -p 'Press Enter to start merge sort timing...' var");
        cout << "Sorting. . . " << endl;
        timer ->resetTimer();
        timer->startTimer();
        mergeSort(array, 0, (length - 1));
        timer->stopTimer();
        cout << "---------" << endl;
        cout << "Time elapsed for merge sort: " << std::setprecision(15) << std::showpoint << std::fixed;
        cout << timer->getSecondsElapsed() << " seconds." << endl;
        cout << "Beginning time: " << timer->getStartTime();
        cout << "End time: " << timer->getEndTime();

        delete array;
        delete timer;

        // //////do fill file with new numbers

        // ofstream outputStream;
        // outputStream.open("toSort.txt");
        // srand(time(0));
        // outputStream << "100000\r\n";
        // for(int i =0;i<100000;++i)
        // {
        //     float toWrite = float(rand()/float(RAND_MAX/100000.00));
        //     outputStream << toWrite<<"\r\n";
        // }
        // cout << "File Filled"<<endl;
        // outputStream.close();

    return 0;
}