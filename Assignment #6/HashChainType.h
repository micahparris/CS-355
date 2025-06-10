// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #6
// Date due: 2/2/2025
// Description: This is the implementation file for the hashChainType
// ---------------------------------------------------------------------------

#ifndef H_HashChainType
#define H_HashChainType

#include "HashADT.h"

using namespace std;

template <class elemType>
class hashChainType: public hashADT<elemType>
{
public:
	hashChainType(int size = 101): hashADT<elemType>(size)
	{
		//no additional action required
	}
	void insert(const elemType& rec);
		//Function to insert an item in the hash table.
		//The item to be inserted is specified by the parameter rec.
		//	Postcondition: rec is inserted in the proper list (create
		//   the list if not already created).

	void search(const elemType& rec, bool& found);
		//Function to determine whether the item specified by the
		//parameter rec is in the hash table.
		//Postcondition: If rec is found, found is set to true,
		//found is set to false.


	void remove(const elemType& rec);
		//Function to remove an item from the hash table.
		//Postcondition: If rec is found in the table it is removed;
		//otherwise, an appropriate error message is displayed.

	void print() const;
		//Function to output the values in the hash table.
};

template <class elemType>
void hashChainType<elemType>::insert(const elemType& rec){
	//WRITE CODE::insert into the hash table
	elemType n = this->getHash(rec);

	// make a new pointer and set it to the list at the hash
	unorderedLinkedList<elemType>* newList = this->HTable[n];

	// if there is no list then make a new one
	if (newList == nullptr) 
	{
		newList = new unorderedLinkedList<elemType>();
	}

	// set the list at the hash to the new list
	this->HTable[this->getHash(rec)] = newList;

	// insert into the list
	newList->insertLast(rec);

}
template <class elemType>
void hashChainType<elemType>::search(const elemType& rec, bool& found){
	//WRITE CODE:: search for an item in the hash table
	// get the hash
	elemType index = this->getHash(rec);
	// search for the value in the list
	found = this->HTable[index]->search(rec);
}
template <class elemType>
void hashChainType<elemType>::remove(const elemType& rec){
	//WRITE CODE:: remove an item from the hash table
	// get hash
	elemType index = this->getHash(rec);
	// delete the value at the hash
	this->HTable[index]->deleteNode(rec);
}
template <class elemType>
void hashChainType<elemType>::print() const{
	//WRITE CODE:: output the values in the hash table.
	for (int i = 0; i < this->HTSize; i++) 
	{
		//if the list is available then print
		if (this->HTable[i] != nullptr)
		{
			this->HTable[i]->print();
		}

		cout << endl;
	}
}

#endif
