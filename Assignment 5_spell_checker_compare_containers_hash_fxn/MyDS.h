// Gustavo J. Munoz
// Assignment 5 - Hashing
// MyDS.h

#ifndef MYDS_1
#define MYDS_1

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

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

class MyDS
{



	public:
	    explicit MyDS(int size = 101);
	    ~MyDS();


	    bool push(const string& x);
	    bool search(const string& x);
	    bool remove(const string& x);

	    void makeEmpty();

	private:
	    vector<list<string> > theLists;
	    int currentSize;
	    MyHash hash;

	    void rehash();
	    int myhash(const string& x) const;
    };

#endif