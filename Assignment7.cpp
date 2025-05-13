// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #7
// Date due: 4/1/2025
// Description: This is the driver file for the recursive functions
//              These will determine what kind of change in US currency and find the highest digit in an integer
// ---------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

// function prototypes
void recursiveChange(int change);
int recursiveInt(int i);

// main function
int main() 
{
    
    recursiveChange(75);
    
    cout << endl << recursiveInt(1) << endl;

    return 0;
}

//---------------------------------------------------------------------------
/* The recursiveChange function will take in a number less than 100 and then recursively check and see how much change is needed in coins
* INCOMING DATA: int
* OUTGOING DATA: None
*/
void recursiveChange(int change)
{
    // check if the change is greater than 99 or there is none
    if (change <= 0 || change > 100) {
        return;
    }

    // recurse through to see what kind of change is due
    if (change >= 25) {
        cout << "Q";
        recursiveChange(change - 25);
    }
    else if(change >= 10) {
        cout << "D";
        recursiveChange(change - 10);
    }
    else if (change >= 5) {
        cout << "N";
        recursiveChange(change - 5);
    }
    else if (change < 5) {
        cout << "P";
        recursiveChange(change - 1);
    }
}

//---------------------------------------------------------------------------
/* The recursiveInt function goes through and integer and searches for the highest digit within the number
* INCOMING DATA: int
* OUTGOING DATA: int
*/
int recursiveInt(int i)
{
    if (i < 10) 
    {
        return i;
    }

    // remove digit by digit 
    int highest = recursiveInt(i / 10);

    // compare the last digit by the highest
    if (i % 10 > highest) 
    {
        return i % 10;
    }
    else 
    {
        return highest;
    }
}
