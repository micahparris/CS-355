// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Project #7
// Date due: 4/27/2025
// Description: This is the driver file provided to us by Professor Ray
// ---------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "HeapImp.h"

int main()
{
    HeapImp myHeap;

    myHeap.printArray();
    myHeap.loadArray();
    myHeap.printArray();

    myHeap.makeHeap();
    myHeap.printArray();

    myHeap.sort();
    myHeap.printArray();

    return 0;
}
