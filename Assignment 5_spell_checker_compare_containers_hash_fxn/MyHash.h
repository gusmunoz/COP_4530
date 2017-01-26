// Gustavo J. Munoz
// Assignment 5 - Binary Search Tree
// dictionary.h

#ifndef MYHAS_1
#define MYHAS_1

#include <iostream>
#include <string>

using namespace std;

class MyHash {
	public:
		size_t operator()(const std::string & key) const {
		    int hashVal = 0;

		    for (unsigned int i = 0; i < key.length(); i++)
			hashVal = 37 * hashVal + key[i];
		    return hashVal;
		}
};

#endif



