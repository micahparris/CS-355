// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #1
// Date due: 1/14/2025
// Description: This is the header file for the fizzbuzz assignment
// ---------------------------------------------------------------------------

#ifndef H_fizz
#define H_fizz
#include <iostream>
using namespace std;


// instance of class fizz
class fizz 
{
private:
    int limit;
public:
    // methods and constructors
    fizz();
    fizz(int l);
    void run();
    void setLimit();
};

#endif