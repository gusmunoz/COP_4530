//Gustavo J. Munoz
//Assignment 2 - Stack.h
//September 30, 2014
//queue implementation using custom Vector class

#ifndef QUEUE_1
#define QUEUE_1

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Vector.h"


using namespace std;


template <typename T>
class queue
{

//Declaration of functions
        public:            
		queue();						//default constructor
		queue(const queue<T>& s);				//copy constructor
		~queue();						//destructor
		
		//accessor
		void push(const T& v);
		void pop();
		T& front();
		bool empty();
		const T& operator=(const queue<T>& rhs);
		
	private:
		Vector<T> array;
		int stackSize;
		int stackCapacity;

		  
};

// Overloaded assignemnt operator
template <typename T>
const T& queue<T>::operator=(const queue<T>& rhs)
{
    if (this != &rhs){
	while (!empty()){
	    pop();
	}
	for (int i = 0; i < rhs.array.containerSize; i++){
	    //automatically incrememnts the internal containerSize
	    array.push_back(rhs.array[i]);
	}
    }
    return *this;
}

// Default constructor -------------------------------------------------------------
template <typename T>
queue<T>::queue()
{
      
}

// Copy constructor ----------------------------------------------------------------
template <typename T>
queue<T>::queue(const queue<T>& s)
{
      
}

// Destructor ----------------------------------------------------------------------
template <typename T>
queue<T>::~queue()
{
  
}


// Insert element ------------------------------------------------------------------
template <typename T>
void queue<T>::push(const T& v)
{
  array.push_back(v);
}

// Remove top element --------------------------------------------------------------
template <typename T>
void queue<T>::pop()
{	
    delete *(front());
    for (int i = 0; i < array.size()-1; i++)
	array[i] = array[i+1];
}

// Access next element -------------------------------------------------------------
template <typename T>
T& queue<T>::front()
{
  return array[0];
}

// Test whether container is empty --------------------------------------------------
template <typename T>
bool queue<T>::empty()
{
    if (array.size() == 0){
	return 1;
    }
    else{
	return 0;
    }
}


#endif









