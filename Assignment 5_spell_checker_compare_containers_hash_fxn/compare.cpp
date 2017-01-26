// Gustavo J. Munoz
// Assignment 5 - Hashing
// compare.cpp

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include "cputime.h"
#include "MyDS.h"
#include "dictionary.h"
#include <string>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

void printResults(double min, double max, double mean, double storageTime, string containerType);
bool printSearchResult(bool searchResult, string containerType);

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
    
    string strTerminal(argv[1]);
    
    Dictionary usrdictdictSET(strTerminal);	
    DictionaryUS usrdictdictUS(strTerminal);	
    DictionaryMyHashUS usrdictMyHashUS(strTerminal);		
    DictionaryMyDS usrdictMyDS(strTerminal);	

    //reading in "Filename.txt" as input file to be checked against dictionary objects
    vector<string> inputFile;  
    vector<string> globalIgnoredWords; 
    
    //parse input file into vector for easy access
    // ifstream ifs(argv[1]);  //dictionary
    ifstream ifs2(argv[2]); //inputfile.txt

    string str;
    
    //read each line/word into vector (for inputfile.txt)
    while (ifs2 >> str) {
	inputFile.push_back(str);
    }
    
    //closing file if previoius condition not met
    ifs2.close();
    

    //store searchTimes
    vector<double> searchTime1;
    vector<double> searchTime2;
    vector<double> searchTime3;
    vector<double> searchTime4;
	
    //check word against 1 dictionary -- iterating through new <vector> input file
    for (vector<string>::iterator it=inputFile.begin(); it!=inputFile.end(); it++){ 
	string word = *it;
	unsigned long long int t1, t2, t3, t4, t5, t6,  t7, t8;	
    
	t1 = cputime();
	usrdictdictSET.search(word);
	t2 = cputime();

	
	t3 = cputime();
	usrdictdictUS.search(word);
	t4 = cputime();


	t5 = cputime();	    
	usrdictMyHashUS.search(word);	    
	t6 = cputime();

	
	t7 = cputime();
	usrdictMyDS.search(word);	    
	t8 = cputime();

	
	//print list of words if found or not and what container was searched
	printSearchResult(usrdictdictSET.search(word), "set");
	printSearchResult(usrdictdictUS.search(word), "hash");
	printSearchResult(usrdictMyHashUS.search(word), "myhash");
	printSearchResult(usrdictMyDS.search(word), "myds");
	
	//store all results for search in a vector
	searchTime1.push_back((t2-t1)*iCPS);
	searchTime2.push_back((t4-t3)*iCPS);
	searchTime3.push_back((t6-t5)*iCPS);
	searchTime4.push_back((t8-t7)*iCPS);
	
    }
    
    //print out the time to search each word
    for (vector<double>::iterator it = searchTime1.begin(); it!=searchTime1.end(); it++){
// 	    cout << "the time for each search for SET: " << *it << endl;
    }
    
    //maximum time for search to happen
    double maxTime1;
    double maxTime2;
    double maxTime3;
    double maxTime4;
    
    //find the maximum search time per word in each container
    maxTime1 = *max_element(searchTime1.begin(), searchTime1.end());
    maxTime2 = *max_element(searchTime2.begin(), searchTime2.end());
    maxTime3 = *max_element(searchTime3.begin(), searchTime3.end());
    maxTime4 = *max_element(searchTime4.begin(), searchTime4.end());



    //maximum time for search to happen
    double minTime1;
    double minTime2;
    double minTime3;
    double minTime4;	
    
    //find the minimum search time per word in each container
    minTime1 = *min_element(searchTime1.begin(), searchTime1.end());
    minTime2 = *min_element(searchTime2.begin(), searchTime2.end());
    minTime3 = *min_element(searchTime3.begin(), searchTime3.end());
    minTime4 = *min_element(searchTime4.begin(), searchTime4.end());

    
    double sum1 = accumulate(searchTime1.begin(), searchTime1.end(), 0.0);
    double meanTime1 = sum1 / searchTime1.size();
    
    double sum2 = accumulate(searchTime2.begin(), searchTime2.end(), 0.0);
    double meanTime2 = sum2 / searchTime2.size();
    
    double sum3 = accumulate(searchTime3.begin(), searchTime3.end(), 0.0);
    double meanTime3 = sum3 / searchTime3.size();	

    double sum4 = accumulate(searchTime4.begin(), searchTime4.end(), 0.0);
    double meanTime4 = sum4 / searchTime4.size();	
	    
    //print the results of timings
    cout << "\n";
    printResults(minTime1, maxTime1, meanTime1, usrdictdictSET.storageTime, "set");
    printResults(minTime2, maxTime2, meanTime2, usrdictdictUS.storageTime, "hash");
    printResults(minTime3, maxTime3, meanTime3, usrdictMyHashUS.storageTime, "myhash");
    printResults(minTime4, maxTime4, meanTime4, usrdictMyDS.storageTime, "myds");
    cout << "\n";
    // write outputFile
    writeVectoFile(inputFile, "outputFile.txt");

    cout << "Thanks for a great semester guys. Nice learning how to program!" << endl;
    cout << "\n";
    return 0;
}

//return TRUE and the name of the container if word is found
bool printSearchResult(bool searchResult, string containerType){
    if(searchResult){
	cout << "Y " << containerType << endl;
    }
    else{
	cout << "N " << containerType << endl;
    }
    
}
//print execution time results:  
//total dictionary store time; min, max, mean, search time for search single word
void printResults(double min, double max, double mean, double storageTime, string containerType){

    cout << containerType << ": store dictionary " << setprecision(2) << storageTime 
		<< " s, search: min " << setprecision(2) << min << " s, " << "max " <<  
		setprecision(2) << max << " s, " << "mean " << setprecision(2) << mean << " s" << endl;

  
}
    
