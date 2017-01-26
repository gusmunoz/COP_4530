// Gustavo J. Munoz
// Assignment 4 - Self-restructuring binary search tree
// MRBST.h

#ifndef MRBST_1
#define MRBST_1

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Restructures by rotating a node with its right child:
// 	if node is found by "search() && if right child exists
// Assume that if a node is found, it is less likely to be searched for in near future

template<typename T>
class MRBST{
	
	// Node class declaration 
	struct Node
	{
	    T data;
	    Node* left;
	    Node* right;

	    Node(const T& theData = T(), Node* LT=NULL, Node* RT=NULL){
		data = theData;
		left = LT;
		right = RT; 
	    }
	};
	
// Prototype declarations ------------------------------------------------------------------------   
  public:
	MRBST();
	MRBST(const MRBST& rhs);
	~MRBST();

	MRBST<T>& operator=(const MRBST<T>& rhs);
	
	bool search(const T& x);
	void PrintPreorder();

	void push(const T& x);
	void makeEmpty();
	void rotateWithRightChild(Node* &k1);

  private:

	Node* root;
	void makeEmpty(Node* &x);
	Node* clone(Node* x) const{
	    if(x == NULL){
		return NULL;
	    }
    
	    return new Node(x->data, clone(x->left), clone(x->right));
	}
	void insert(const T& x, Node* &t);
	bool contains(const T& x, Node *& t);
	void PrintPreorderPrivate(Node* t);

};

// Default constructor ---------------------------------------------------------------------------
template<typename T>
MRBST<T>::MRBST()
{
   root = NULL; 
}

// Copy constructor ------------------------------------------------------------------------------
template<typename T>
MRBST<T>::MRBST(const MRBST& rhs)
{
    root = NULL;
    root = clone(rhs.root);
}

// Destructor ------------------------------------------------------------------------------------
template<typename T>
MRBST<T>::~MRBST()
{
    makeEmpty();
}

//  Assignment constant Operator = ---------------------------------------------------------------
template<typename T>
MRBST<T>& MRBST<T>::operator=(const MRBST<T>& rhs)
{
    if(this != &rhs){
	makeEmpty();
	root = clone(rhs.root);
    }
    return *this;
}

// search() --------------------------------------------------------------------------------------
// returns true iff 'x' is present in the tree; 
//also causes restructuring to be performed
template<typename T>
bool MRBST<T>::search(const T& x)
{
  //const T* p = &x;
    if(contains(x,root)){
	return true;
    }
    else{
	return false;
    }
}

template<typename T>
// contains() ------------------------------------------------------------------------------------
// private member function called by search(). 'x' is item to search for; 't' is node that roots the subtree
bool MRBST<T>::contains(const T& x, Node *& t)
{
    if(t == NULL){
	return false;
    }
    else if(x < t->data){
	return contains(x, t->left);
    }
    else if(t->data < x){
	return contains(x, t->right);
    }
    else{
	if(t->right != NULL){
	    rotateWithRightChild(t);
	    return true;
	}
	else{
	    cout << "Node " << t->data << " does not contain a right child. No rotation performed." << '\n';
	    return true;
      }
    }
}

template<typename T>
void MRBST<T>::rotateWithRightChild(Node*& k1)
{   
    Node *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = &*k2;
}

// PrintPreorder() -------------------------------------------------------------------------------
// prints the values stored in each node using pre-order traversal
template<typename T>
void MRBST<T>::PrintPreorder()
{
    if(root != NULL){
	PrintPreorderPrivate(root);
    }
    else{
	cout << "\tThe tree is empty.\n";
    }
}

// PrintPreorderPrivate() PRIVATE -----------------------------------------------------------------
// private function called by print preorder -- preorder
template<typename T>
void MRBST<T>::PrintPreorderPrivate(Node* t)
{
    cout << '\t' << t->data << " " << '\n';

    if(t->left != NULL){
	PrintPreorderPrivate(t->left);
    }

    if(t->right != NULL){
	PrintPreorderPrivate(t->right);
    }
}

// push() ----------------------------------------------------------------------------------------
// inserts node into the tree
template<typename T>
void MRBST<T>::push(const T& x)
{
    insert(x, root);
}

// makeEmpty() -----------------------------------------------------------------------------------
// private 1-param member fxn
template<typename T>
void MRBST<T>::makeEmpty(Node* &x)
{
    if(x != NULL){
	makeEmpty(x->left);
	makeEmpty(x->right);
	delete x;
    }
    x = NULL;
}

// makeEmpty() -----------------------------------------------------------------------------------
// public member fxn calling private recursive member fxn
template<typename T>
void MRBST<T>::makeEmpty()
{
    makeEmpty(root);
}

// insert() --------------------------------------------------------------------------------------
// private insert function called by push()
template<typename T>
void MRBST<T>::insert(const T& x, Node* &t)
{
    if(t == NULL){
	t = new Node(x,NULL,NULL);
    }
    else if(x < t->data){
      insert(x,t->left);
    }
    else if(t->data < x){
      insert(x,t->right);
    }
    else{
    }
}

#endif