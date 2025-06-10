// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #4
// Date due: 1/14/2025
// Description: This is the header file for the stack iterator
// ---------------------------------------------------------------------------


#ifndef H_SI
#define H_SI

#include "myStack.h"
#include <iostream>
using namespace std;

template <class Type>
class stackIterator
{
	private:
		int tracker;
		Type *ptrList;
	public: 
		stackIterator(stackType<Type> stack);
		stackIterator<Type>& operator++();
		stackIterator<Type> operator++(int);
		Type& operator*();
		
		void print();
};

template <class Type>
stackIterator<Type>::stackIterator(stackType<Type> stack)
{
	tracker = stack.getTop() - 1;
	ptrList = stack.getList();
}

template <class Type>
stackIterator<Type>& stackIterator<Type>::operator++()
{
	if (tracker > 0) 
	{
		tracker++;
	}

	return *this;
}


template <class Type>
stackIterator<Type> stackIterator<Type>::operator++(int)
{
	stackIterator<Type> temp = *this;

	if (tracker > 0) 
	{
		tracker--;
	}
	else if (tracker <= 0)
	{
		tracker = 0;
	}

	return temp;
}


template <class Type>
Type& stackIterator<Type>::operator*()
{
	return ptrList[tracker];
}

template <class Type>
void stackIterator<Type>::print()
{
	cout << tracker << endl;
}
#endif