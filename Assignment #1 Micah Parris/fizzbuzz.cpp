// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #1
// Date due: 1/14/2025
// Description: This is the implementation file for the fizzbuzz
// ---------------------------------------------------------------------------

#include <iostream>
#include "fizz.h"

using namespace std;

//---------------------------------------------------------------------------
/* The fizz() constructor is the default constructor
* INCOMING DATA: None 
* OUTGOING DATA: None
*/
fizz::fizz() 
{
    // 100 is the default limit
    limit = 100;
};

//---------------------------------------------------------------------------
/* The fizz(int l) constructor takes in an integer and sets the limit to that integer
* INCOMING DATA: None
* OUTGOING DATA: None
*/
fizz::fizz(int l) 
{
    // set the limit to the parameter 
    limit = l;
}

//---------------------------------------------------------------------------
/* The run() method allows for the fizzbuzz game to be played
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void fizz::run() 
{
    // for loop to go through the game until the limit is reached
    for (int i = 1; i < limit + 1; i++) 
    {
        // if the number is divisible by 3 and 5 then output fizzbuzz
        if (i % 3 == 0 && i % 5 == 0) 
        {
            cout << "FizzBuzz" << endl;
        }
        // if the number is only divisible by 3 then output fizz
        else if (i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        // if the number is only divisible by 5 then output buzz
        else if (i % 5 == 0)
        {
            cout << "Buzz" << endl;
        }
        // if none of the above apply then just output the number
        else 
        {
            cout << i << endl;
        }
    }
    // spacing for when the game ends
    cout << endl << endl;
};



//---------------------------------------------------------------------------
/* The setLimit() asks the user for a number and then sets the limit to that number
* INCOMING DATA: None
* OUTGOING DATA: None
*/
void fizz::setLimit() 
{
    // integer to keep up with the number
    int v = 1;
    
    // prompting user
    cout << "Enter a limit: ";
    cin >> v;

    // set limit to number
    limit = v;

    // spacing for when the method is done
    cout << endl << endl;
}
