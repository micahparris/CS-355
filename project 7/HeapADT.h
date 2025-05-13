// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Project #7
// Date due: 4/27/2025
// Description: This is the header file for the HeapADT provided to us by Professor Ray
// ---------------------------------------------------------------------------

class HeapADT{
    public:
    	virtual void loadArray() = 0;
    	virtual void makeHeap() = 0;
    	virtual void printArray() = 0;
    	virtual void sort() = 0;
};
