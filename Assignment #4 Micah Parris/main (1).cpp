#include <iostream>

#include "myStack.h"
#include "stackIterator.h"

using namespace std;

int main()
{
   stackType<int> stack1(10);
   stack1.push(6);
   stack1.push(12);
   stack1.pop();
   stack1.push(17);
   stack1.push(25);
   stack1.push(42);
   stack1.push(34);

   
   //create a stackIterator as in: stackIterator<int> it;
   stackIterator<int> it1(stack1);
   it1++;
   it1++;
   cout << *it1;
   

   
   
   //Use your stackIterator in a simple for loop here that iterates
   //over the entire stack and prints the stack out 
   //(make use of the overloaded ++ and * to do so)
}
