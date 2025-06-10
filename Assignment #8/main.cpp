// ---------------------------------------------------------------------------
// Name: Micah Parris
// Course-Section: CS355-section 1
// Assignment: Assignment #8
// Date due: 4/11/2025
// Description: This is the driver file for the BST
// ---------------------------------------------------------------------------


#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> bst;

    int temp;

    for(int i=0; i<5; i++){
        cin>>temp;
        bst.insert(temp);
    }

    cout<<"In-Order Traversal"<<endl;
    bst.inorderTraversal();
    cout<<endl<<"Pre-Order Traversal"<<endl;
    bst.preorderTraversal();
    cout<<endl<<"Post-Order Traveral"<<endl;
    bst.postorderTraversal();
    // implemented methods
    bst.minimum();
    bst.maxInTree();
    bst.print();


    return 0;
}
