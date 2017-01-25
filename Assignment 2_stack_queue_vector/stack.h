//Gustavo J. Munoz
//Assignment 2 - Stack.h
//September 30, 2014
//stack implementation using custom Vector class

#ifndef STACK_1
#define STACK_1

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Vector.h"


using namespace std;


template <typename T>
class stack
{

        public:            
		stack();						//default constructor
		stack(const stack<T>& s);				//copy constructor
		~stack();						//destructor
		
		//accessor
		void push(const T& n);
		void pop();
		T& top();
		bool empty();
		
	private:
		Vector<T> array;

		  
};


// Default constructor -------------------------------------------------------------
template <typename T>
stack<T>::stack()
{
      
}

// Copy constructor ----------------------------------------------------------------
template <typename T>
stack<T>::stack(const stack<T>& s): array(s.array)
{
  
}

// Destructor ----------------------------------------------------------------------
template <typename T>
stack<T>::~stack()
{

}

// Insert element ------------------------------------------------------------------
template <typename T>
void stack<T>::push(const T& n)
{
    array.push_back(n);
}

// Remove top element --------------------------------------------------------------
template <typename T>
void stack<T>::pop()
{
    array.pop_back();
}

// Access next element -------------------------------------------------------------
template <typename T>
T& stack<T>::top()
{
    return array[(array.size())-1];
}

// Test whether container is empty --------------------------------------------------
template <typename T>
bool stack<T>::empty()
{
    if (array.size() == 0){
	return 1;
    }
    else{
	return 0;
    }
}

#endif
