// Gustavo J. Munoz
// Assignment 3 - Spell Checker
// Header File - Node

#ifndef LINKEDLIST_1
#define LINKEDLIST_1

#include <fstream>
#include <iostream>
#include <string>


using std::string;
using std::swap;
using std::copy;


class LinkedList
{
    struct Node
    {
	string data;
	Node* prev;
	Node* next;
	int count;


	Node(const string& d = "", Node* p = NULL, Node* n = NULL, int c = 0)
	{
	  data = d;
	  prev = p;
	  next = n; 
	  count = c;
	}
    };
	
  public:
// Const iterator ---------------------------------------------------------------------------
    class iterator
    {
      friend LinkedList;
      
      public:
	iterator() {
	    current = NULL;
	}
	string& operator*(){
	    return retrieve();
	}
	iterator& operator++(){
	    current = current->next;
	    return *this;
	}
	iterator operator++(int){
	    iterator old = *this;
	    ++(*this);
	    return old;
	}
	iterator& operator--(){
	    current = current->prev;
	    return *this;
	}
	iterator operator--(int){
	    iterator old = *this;
	    --(*this);
	    return old;
	}	
	bool operator==(const iterator& rhs) const{
	    return current == rhs.current;
	}
	bool operator!=(const iterator& rhs) const{
	    return !(*this == rhs);
	}
	
      protected:
	Node* current;
	string& retrieve() const{
	    return current->data;
	}
	iterator(Node *p){
	    current = p;
	}
    };
    
	LinkedList();
	LinkedList(const LinkedList& rhs);
	~LinkedList();

	LinkedList &operator=(const LinkedList& rhs);
	
	int length() const;
	bool empty() const;
	void clear();

	string &front();
	const string &front() const;
	string &back();
	const string &back() const;
	
	void push_front(const string& x);
	void push_back(const string& x);
	void pop_front();
	void pop_back();

	iterator insert(iterator itr, const string& x);
	iterator erase(iterator itr);
	iterator erase(iterator from, iterator to);
	
	iterator find(const string& val);

	iterator begin();
	iterator end();
	iterator begin() const;
	iterator end() const;

  private:
    	int size;
	Node* head;
	Node* tail;

};

// Default constructor ---------------------------------------------------------------------------
LinkedList::LinkedList()
{
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

// Copy constructor ------------------------------------------------------------------------------
LinkedList::LinkedList(const LinkedList& rhs)
{
    LinkedList copy = rhs;
    swap(*this, copy);
}

// Destructor ------------------------------------------------------------------------------------
LinkedList::~LinkedList()
{
    clear();
    delete head;
    delete tail;
}

//  Assignment constant Operator = ---------------------------------------------------------------
LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    LinkedList copy = rhs;
    swap(*this, copy);
    return *this;
}

// length() - Return size of linked list -----------------------------------------------------------
int LinkedList::length() const
{
    return size;
}
// empty() - Check is container is empty ---------------------------------------------------------
bool LinkedList::empty() const
{
    return (length() == 0);
}

// clear() - clear any elements in linked list ---------------------------------------------------
void LinkedList::clear()
{
    while (!empty()){
	pop_front();
    }
}

// front() - Access first element ----------------------------------------------------------------
string& LinkedList::front()
{
    return *begin();
}

// back() Return const reference to last element in container ------------------------------------
string& LinkedList::back()
{
    return *--end();
}

// push_front() Insert element at beginning of container -----------------------------------------
void LinkedList::push_front(const string& x)
{
    insert(begin(), x); 
}

// push_back() Insert element at end of container -----------------------------------------------
void LinkedList::push_back(const string& x)
{
    insert(end(), x); 
}

// pop_front() Removes the first element in the list container ----------------------------------
void LinkedList::pop_front()
{
    erase(begin());
}

// pop_back() Removes the last element in the list container ------------------------------------
void LinkedList::pop_back()
{
    erase(--end());
}

// begin() points to beginning node -------------------------------------------------------------
LinkedList::iterator LinkedList::begin()
{
    return iterator(head->next);
}

// begin() points to beginning node -------------------------------------------------------------
LinkedList::iterator LinkedList::begin() const
{
    return iterator(head->next);
}
	
// end() Returns an iterator referring to the past-the-end element in the list container -------- 
LinkedList::iterator LinkedList::end()
{
    return iterator(tail);
}

// end() const Returns an iterator referring to the past-the-end element in the list container -------- 
LinkedList::iterator LinkedList::end() const
{
    return iterator(tail);
}

// Insert() Insert elements anywhere ------------------------------------------------------------
LinkedList::iterator LinkedList::insert(LinkedList::iterator itr, const string& x)
{
    Node* tempNode = new Node(x, itr.current->prev, itr.current);
    itr.current->prev->next = tempNode;
    itr.current->prev = tempNode;
    size++;
    return ( itr );
}

// erase() Removes single or range of elements ----------------------------------------------------------
LinkedList::iterator LinkedList::erase(LinkedList::iterator itr)
{
    Node* temp = itr.current;
    iterator x = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    size--;
    return x;
  
}
  
// find() -------------------------------------------------------------------------------------
LinkedList::iterator LinkedList::find(const string& val)
{
    for(LinkedList::iterator it = begin(); it != end(); ++it){
	if( *it == val) {
	    return it;
	}
    }
    return end();
}


#endif