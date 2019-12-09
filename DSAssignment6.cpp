/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 6 Sorting Algorithm analysis
*/
#include <iostream>
#include <string>
#include "Timer.h"
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

//implements basic version of bubble sort by continutally comparing each instance to the preceeding one
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
//implements basic selection sort by placing each value in its corrects spot on eindex at a time
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
//uses a marker and assumes that everything to the left is partially sorted to avoid while loop
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
//takes in three arrays and their sizes to merge the first two into the third one
void merge(double* arr1,int size1,double* arr2,int size2,double* arr,int sizeArr)
{
    int i = 0;
    int j = 0;
    int x = 0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[x] = arr1[i];
            x++;
            i++;
        }
        else 
        {
            arr[x] = arr2[j];
            x++;
            j++;
        }
    }
    while(i <size1)
    {
        arr[x] = arr1[i];
        x++;
        i++;
    }
    while(j <size2)
    {
        arr[x] = arr2[j];
        x++;
        j++;
    }
}

//sorts an array of doubles by breaking them down then remerging them together
void mergeSort(double* theArray,int length)
{
    if(length <= 1)
        return;
    int halfSize = length/2;
    int backSize = length-halfSize;
    double *arr1 = new double[halfSize];
    double *arr2 = new double[backSize];
    for(int i =0; i <halfSize;++i)
    {
        arr1[i] = theArray[i];
    }
    int index = 0;
    for(int i = halfSize;i<length;++i)
    {
        arr2[index++] = theArray[i];
    }   
    mergeSort(arr1,halfSize);
    mergeSort(arr2,backSize);
    
    merge(arr1,halfSize,arr2,backSize,theArray,length);

}
//used to copy one array to another
void copyArray(double *firstArray, double *secondArray, int length)
{
    for (int i = 0; i < length; ++i)
    {
        secondArray[i] = firstArray[i];
    }
}

    int main(int arc, char **argv)
    {
        //if any 3rd numeric argument given fill file with new randomized numbers
        //otherwise just use the file that was already created
        if(argv[2])
        {
            int numWrite = std::stoi(argv[2]);
            ofstream outputStream;
            outputStream.open(argv[1]);
            srand(time(0));
            outputStream << numWrite<<"\r\n";
            for (int i = 0; i < numWrite; ++i)
            {
                double toWrite = double(rand() / double(RAND_MAX / 100000.00));
                outputStream << toWrite << "\r\n";
            }
            cout << "File Filled with new random numbers" << endl;
            outputStream.close();
        }      


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
        //get the number of doubles to sort
        int length = std::stoi(fileIn);
        double *array = new double[length];
        double *secondArray = new double[length];
        double *thirdArray = new double[length];
        double *fourthArray = new double[length];
        Timer *timer = new Timer();

     

        //read in the data
        double indouble;
        int index = 0;
        while (getline(inputStream, fileIn))
        {
            indouble = std::stof(fileIn);
            array[index] = indouble;
            index++;
        }
        inputStream.close();
        //make copies of each array
        copyArray(array, secondArray, length);
        copyArray(array,secondArray,length);
        copyArray(array,thirdArray,length);
        copyArray(array,fourthArray,length);



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
        // mergeSort(array, 0, (length - 1));
        mergeSort(array,length);
        timer->stopTimer();
        cout << "---------" << endl;
        cout << "Time elapsed for merge sort: " << std::setprecision(15) << std::showpoint << std::fixed;
        cout << timer->getSecondsElapsed() << " seconds." << endl;
        cout << "Beginning time: " << timer->getStartTime();
        cout << "End time: " << timer->getEndTime();

        //delete all dynamically allocated memory
        delete [] array;
        delete  [] secondArray;
        delete  [] thirdArray;
        delete  [] fourthArray;
        delete timer;



    return 0;
}