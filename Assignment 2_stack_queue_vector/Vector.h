//Gustavo J. Munoz
//Assignment 2 - Vector.h
//September 30, 2014
//custom Vector class

#ifndef VECTOR_1
#define VECTOR_1

#include <iostream>
#include <math.h>
#include <stdlib.h>



using namespace std;


//class template
template <typename T>
class Vector
{

//Declaration of functions
        public:            
		Vector();						//default constructor
		Vector(const int begin, const int end, const T* a);	//3 parameter constructor
		Vector(const Vector<T>& v);				//copy constructor
		~Vector();						//destructor
		
		//accessor
		const T& operator[](int index) const;
		T& operator[](int index);

		
		//gettor 
		int size() const;
		int capacity() const;
		
		//modifiers
		void pop_back();
		void push_back(const T& e);
			
		void reserve(int newCapacity);
		
                
	private:
		int containerSize; 					// size of array
		int containerCapacity; 					// capacity of array
		T *array;     						// current array
		T *newArray(int space);					// array used for space allocation
		  
};


// Operator overload:  Accessor -------------------------------------------------
template <typename T>
const T& Vector<T>::operator[](int index) const
{
    if (index >= containerCapacity){
	cout << "Accessor out of bounds!" << endl;
	exit(EXIT_FAILURE);
    }
    else{
	return array[index];
    }
}

// Operator overload:  Mutator --------------------------------------------------
template <typename T>
T& Vector<T>::operator[](int index)
{
    if (index >= containerCapacity){
	cout << "Accessor out of bounds!" << endl;
	exit(EXIT_FAILURE);
    }
    else{
	return array[index];
    }
}

// Container space allocator ----------------------------------------------------
template <typename T>
T* Vector<T>::newArray(int space)
{
    T* oldArray = 0;
    oldArray = new (nothrow) T[space];
    if (oldArray == 0){
	cout << "Failed!\n";
    }
    else{
	cout << "Succeeded!\n"; 
    }
	return oldArray;
}


// Default constructor ----------------------------------------------------------
template <typename T>
Vector<T>::Vector()
{
    containerSize = 0;
    containerCapacity = 2;    
    array = new T[containerCapacity];
    if (array == NULL){
      cout<< "cannot allocate memory" << endl;
      exit(EXIT_FAILURE);   
    } 
}

// 3-parameter constructor -------------------------------------------------------
template <typename T>
Vector<T>::Vector(const int begin, const int end, const T* copyArray)
{  
    int length = end - begin +1;
    if (length < 0){
    cout << "Error: Invalid range for vector array.\n";
    exit(EXIT_FAILURE);
    }
    containerCapacity = 4*length;
    array = newArray(containerCapacity);
    containerSize = length;
    for (int i = 0; i < length; i++){
	array[i] = copyArray[begin+i];
    }
}

// Copy constructor --------------------------------------------------------------
template <typename T>
Vector<T>::Vector(const Vector<T>& v)
{
    array = newArray(v.containerCapacity);
    containerCapacity = v.containerCapacity();
    containerSize = v.containerSize();
    for (int i = 0; i < v.containersize; ++i){
	array[i] = v.array[i];
    }    
}

// Destructor -------------------------------------------------------------------
template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
}

// Request a change in capacity -------------------------------------------------
template <typename T>
void Vector<T>::reserve(int newCapacity)
{
    if (containerSize > newCapacity){
	cout << "Error: Current container size is larger than requested capacity\n";
	exit(EXIT_FAILURE);
    }
    if (containerCapacity == newCapacity){
	    return;
	
    }
    else{
	if (containerCapacity > newCapacity){
	return;
	}
	else{
	T *oldArray = array;
	array = newArray(newCapacity);
	for (int i=0; i < size(); i++){
	    array[i] = oldArray[i];
	}
	containerCapacity = newCapacity;
	delete [] oldArray;
	}
    }
}

// Return size ------------------------------------------------------------------
template <typename T>
int Vector<T>::size() const
{
  return containerSize;
}

// Return size of allocated storage capacity ------------------------------------
template <typename T>
int Vector<T>::capacity() const
{
  return containerCapacity;
}

// Delete last element ----------------------------------------------------------
template <typename T>
void Vector<T>::pop_back()
{
    if (size() == 0){
	return;
    } 
    else{
    containerSize--; 
    }
}

// Add element at the end -------------------------------------------------------
template <typename T>
void Vector<T>::push_back(const T& e)
{
  if (containerSize == containerCapacity){
    reserve(4*containerSize);
  }
  array[containerSize] = e;
  containerSize++;
  
}


#endif
