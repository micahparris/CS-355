// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #1
// Date due: 1/14/2025
// Description: This is the driver file for the fizzbuzz
// ---------------------------------------------------------------------------

// included files
#include <iostream>
#include "fizz.h"
#include "fizzbuzz.cpp"

using namespace std;

int main() 
{
    //instance of fizz class
    fizz f1;
    // integer to keep up with the user choice
    int choice = 0;

    // do while to keep the game going until the user quits
    do 
    {
        // list of choices
        cout << "1. Run fizzbuzz" << endl;
        cout << "2. Set limit" << endl;
        cout << "0. Quit" << endl;
        // where the user inputs their choice
        cout << "Enter choice here: ";
        cin >> choice;

        // switch statement to determine which action is taken based on input
        switch (choice) 
        {
            // if the user chooses 1 then run the game and stop
            case 1:
                f1.run();
                break;
            // if the user chooses 2 then ask for a limit, set it, then stop
            case 2:
                f1.setLimit();
                break;
        }
      // while the choice is not 0 then the game will keep going
    } while (choice != 0);
}