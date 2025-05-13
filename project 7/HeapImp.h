// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #9
// Date due: 4/30/2025
// Description: This is the header file for the weighted graph type
// ---------------------------------------------------------------------------


#ifndef H_HI
#define H_HI

#include "HeapADT.h"

class HeapImp : public HeapADT
{
private:
    int* array;
    int size;
public:
    HeapImp();
    void loadArray();
    void makeHeap();
    void printArray();
    void sort();
    void heapify(int arr[], int size, int i);
};





#endif