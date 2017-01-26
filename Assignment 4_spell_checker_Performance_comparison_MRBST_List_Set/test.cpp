// Gustavo J. Munoz
// Assignment 4 - test.cpp
// AVL implementation used

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "MRBST.h"

using namespace std;


int main(int argc, char* argv[]) 
{			
    MRBST<int> myBST1;
    
    cout << '\n';
    cout<< "**********(Integer) Printing tree using PREORDER traversal.**********\nBefore adding numbers:" << '\n';
    myBST1.PrintPreorder();
    
    myBST1.push(50);
    myBST1.push(25);
    myBST1.push(1);
    myBST1.push(75);
    myBST1.push(30);
    myBST1.push(62);
    myBST1.push(63);
    myBST1.push(24);
    myBST1.push(39);
    myBST1.push(150);
    myBST1.push(160);
    
//populating tree
    cout<< "After adding numbers:" << '\n';
    myBST1.PrintPreorder();

//23 does not exist.
    cout<< "After searching for Node 23:" << '\n';
    myBST1.search(23);
    myBST1.PrintPreorder();
    
//75 exists and has a right child. rotatioin performed.
    cout<< "After searching for Node 75:" << '\n';
    myBST1.search(75);
    myBST1.PrintPreorder();
    
//160 exists but does not have a right child.
    cout<< "After searching for Node 160:" << '\n';
    myBST1.search(160);
    myBST1.PrintPreorder();
    

}


   























