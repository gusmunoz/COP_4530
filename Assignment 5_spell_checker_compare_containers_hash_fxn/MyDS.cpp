// Gustavo J. Munoz
// Assignment 5 - Hashing
// MyDS.h

#ifndef MYDS_H
#define MYDS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "MyDS.h"
#include <algorithm>


using namespace std;


MyDS::MyDS(int size) 
{    
    currentSize = 0;
    theLists.resize(101);
}

MyDS::~MyDS(){
  
}

bool MyDS::push(const string& x)
{
    list<string>& whichList = theLists[myhash(x)];

    if(find(whichList.begin(), whichList.end(), x) != whichList.end())
        return false;
    
    whichList.push_back(x);
    
    //rehash; section 5.5
    if(++currentSize > theLists.size())
        rehash();

    return true;
}

bool MyDS::search(const string& x)
{
    const list<string>& whichList = theLists[myhash(x)];
    return find(whichList.begin(), whichList.end(), x) != whichList.end();
    
}

void MyDS::makeEmpty()
{
    for(int i = 0; i < theLists.size(); i++)
        theLists[i].clear();
}

bool MyDS::remove(const string& x)
{
    list<string>& whichList = theLists[myhash(x)];
    list<string>::iterator itr = find(whichList.begin(), whichList.end(), x);
  
    if(itr == whichList.end())
        return false;
    
    whichList.erase(itr);
        --currentSize;

    return true;
}

bool isPrime( int n )
{
    if( n == 2 || n == 3 )
	return true;
    if( n == 1 || n % 2 == 0 )
	return false;
    for( int i = 3; i * i <= n; i += 2 )
	if( n % i == 0 )
	    return false;
    return true;
}


int nextPrime( int n )
{
    if( n % 2 == 0 )
        n++;
    for( ; !isPrime( n ); n += 2 )
        ;
    return n;
}

void MyDS::rehash()
{
    vector<list<string> > oldLists = theLists;
    
    //create new double-sized, empty table
    theLists.resize(nextPrime(2*theLists.size()));
    for(int j = 0; j < theLists.size();j++)
        theLists[j].clear();
    
    //copy table over
    currentSize = 0;
    for(int i = 0; i < oldLists.size(); i++){
        list<string>::iterator itr = oldLists[i].begin();

        while(itr != oldLists[i].end())
            push(*itr++);
    }
}

int MyDS::myhash(const string& x) const 
{

    int hashVal = hash(x);
    
    hashVal %= theLists.size();
    
    if(hashVal < 0)
        hashVal += theLists.size();
    
    return hashVal;
    
}


#endif