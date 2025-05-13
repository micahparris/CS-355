// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Project #7
// Date due: 4/27/2025
// Description: This is the implementation file for the HeapImp class
// ---------------------------------------------------------------------------

#include "HeapImp.h"

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------
/* This is the default constructor for the HeapImp class
* INCOMING DATA: None
* OUTGOING DATA: None
*/
HeapImp::HeapImp()
{
    array = nullptr;
    size = 0;
}

//---------------------------------------------------------------------------
/* The printArray method will just go through and print every element in the array
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void HeapImp::printArray()
{
    // if list is empty output message
    if (array == nullptr)
    {
        cout << "List is empty";
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

//---------------------------------------------------------------------------
/* The loadArray method will ask for a file name and then read the values from that file into the array
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void HeapImp::loadArray()
{
    ifstream infile;
    string fileName = " ";
    int i = 0;

    // prompt for file name
    cout << "Enter file Name: ";
    cin >> fileName;

    infile.open(fileName);

    // if file is not open output an error message and stop program
    if (!infile.is_open())
    {
        cout << "ERROR OPENING FILE" << endl;
        exit(1);
    }
    else{
        // read the first value for the size
        infile >> size;

        // allocate a new array of integers
        array = new int[size];

        // read the rest of the elements in the file into the array
        while (infile >> array[i] && i < size)
        {
            i++;
        }
        
        cout << "INFO FROM FILE READ CORRECTLY" << endl;
    }

    // close file when done
    infile.close();
}

//---------------------------------------------------------------------------
/* The makeHeap method will go through and call heapify to for a heap to be made
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void HeapImp::makeHeap()
{
    int index = (size / 2) - 1;

    for (int i = index; i >= 0; i--)
    {
        heapify(array, size, i);
    }

}


//---------------------------------------------------------------------------
/* The sort method will sort the array from least to greatest with the help of the heapify method
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void HeapImp::sort()
{
    int length = size;

    // heapify if not done already
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        heapify(array, length, i);
    }

    // sort the array
    for (int i = length - 1; i > 0; i--) 
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }

}

//---------------------------------------------------------------------------
/* The heapify method will recursively go through and rearrange the elements in the array to form a heap
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void HeapImp::heapify(int arr[], int size, int i)
{
    int largeNum = i;
    // for the left and right child index
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    
    if ( left < size && arr[left] > arr[largeNum])
    {
        largeNum = left;
    }
    if (right < size && arr[right] > arr[largeNum])
    {
        largeNum = right;
    }
    // swap elements and recurse
    if (largeNum != i)
    {
        int temp = arr[i];
        arr[i] = arr[largeNum];
        arr[largeNum] = temp;

        heapify(arr, size, largeNum);
    }
}