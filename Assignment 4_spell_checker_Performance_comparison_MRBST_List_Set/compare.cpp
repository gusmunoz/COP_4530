// Gustavo J. Munoz
// Assignment 4 - Binary Search Tree
// compare.cpp

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "dictionary.h"
#include <stdio.h>
#include <unistd.h>
#include "cputime.h"
#include "cputime.c"
#include <sys/time.h>


void printVector(vector<string> inputFile) {
  
    for (vector<string>::iterator it=inputFile.begin(); it!=inputFile.end(); it++){
	cout <<  *it <<  endl;
    }
}

void writeVectoFile(vector<string> inputFile, string outputFn){

    fstream ofs(outputFn.c_str(), fstream::out);
    string carriageRet = "\n";
    for(vector<string>::iterator it=inputFile.begin(); it!=inputFile.end();it++){
	if(carriageRet.compare(*it)==0)
	    ofs << *it;
	else
	    ofs << *it << " ";
    }
    ofs.close();
}

int main(int argc, char* argv[]) {			

    //dictionaries in linprog in 3 containers
    Dictionary usrdictSET("words");	
    DictionaryLL usrdictLIST("words");		
    DictionaryMRBST usrdictMRBST("words");	

    //reading in "Filename.txt" as input file to be checked against dictionary objects
    vector<string> inputFile;  
    vector<string> globalIgnoredWords; //not sure what this is.. ill see below

    //parse input file into vector for easy access
    ifstream ifs(argv[1]);
    string str;

    //read each line/word into vector
    while (ifs >> str) {
	inputFile.push_back(str);
    }

    //closing file if previoius condition not met
    ifs.close();

    //check word against both dictionaries -- iterating through new <vector> input file
    for (vector<string>::iterator it=inputFile.begin(); it!=inputFile.end(); it++){ 
	string word = *it;
	
	double t1, t2;
	t1 = cputime();
	usrdictSET.search(word);
	t2 = cputime();
	cout << word << ", SET, " << t2-t1 << " seconds" << std::endl;
	
	double t3, t4;
	t3 = cputime();
	usrdictLIST.search(word);
	t4 = cputime();
	cout << word << ", LIST, " << t4-t3 << " seconds" << std::endl;
	
	double t5, t6;	  
	t5 = cputime();
	usrdictMRBST.search(word);
	t6 = cputime();
	cout << word << ", MRBST, " << t6-t5 << " seconds" << std::endl;
	
    }

    // write outputFile
    writeVectoFile(inputFile, "outputFile.txt");

    return 0;
  
}





























