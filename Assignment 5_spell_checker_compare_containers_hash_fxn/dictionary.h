// Gustavo J. Munoz
// Assignment 5 - Binary Search Tree
// dictionary.h

#include <fstream>
#include <set>
#include <list>
#include <locale>
#include <algorithm>
#include <unordered_set>
#include "MyDS.h"
#include "cputime.h"


using namespace std;

// Using <set> STL ------------------------------------------------------------------------------------
class Dictionary{

        public:
		set<string> dictSet; 			
		locale loc;
		string fileLoc;
		unsigned long long int t1, t2;
		double storageTime;
		
                Dictionary(string fileLocation){	

		    fileLoc = fileLocation;
		    t1 = cputime();
		    fstream ifs(fileLocation.c_str(), fstream::in);	
		    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictSet.insert(str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
		    t2 = cputime();
		    storageTime = (t2 - t1)*iCPS;
			
                }
               
                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);
		    
		    return((dictSet.find(loWord) != dictSet.end()) || (dictSet.find(upWord) != dictSet.end())); 
		  
		}
};

// Using <unordered_set> STL (default)-------------------------------------------------------------------
class DictionaryUS{
        public:
		unordered_set<string> dictUS; 			
		locale loc;
		string fileLoc;
		unsigned long long int t1, t2;
		double storageTime;

		
                DictionaryUS(string fileLocation){	

		    fileLoc = fileLocation;
		    t1 = cputime();
		    fstream ifs(fileLocation.c_str(), fstream::in);	
		    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictUS.insert(dictUS.end(), str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
		    t2 = cputime();
		    storageTime = (t2 - t1)*iCPS;
		}

                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		    
		    return((dictUS.find(loWord) != dictUS.end()) || (dictUS.find(upWord) != dictUS.end())); 

		}
};

// Using <unordered_set> STL (MyHash)-------------------------------------------------------------------
class DictionaryMyHashUS{
        public:
		unordered_set<string, MyHash> dictMyHashUS; 			
		locale loc;
		string fileLoc;
		unsigned long long int t1, t2;
		double storageTime;
		
		
                DictionaryMyHashUS(string fileLocation){	

		    fileLoc = fileLocation;
		    t1 = cputime();
		    fstream ifs(fileLocation.c_str(), fstream::in);	
		    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictMyHashUS.insert(dictMyHashUS.end(), str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
		    t2 = cputime();
		    storageTime = (t2 - t1)*iCPS;
		}

                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);
		    
		    return((dictMyHashUS.find(loWord) != dictMyHashUS.end()) || (dictMyHashUS.find(upWord) != dictMyHashUS.end())); 
		    
		}
};

// Using MyDS ----------------------------------------------------------------------------------------
class DictionaryMyDS{

        public:
		MyDS dictMyDS; 			
		locale loc;
		string fileLoc;
		unsigned long long int t1, t2;
		double storageTime;		
		
                DictionaryMyDS(string fileLocation){	

		    fileLoc = fileLocation;
		    t1 = cputime();
		    fstream ifs(fileLocation.c_str(), fstream::in);	
					    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictMyDS.push(str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
		    t2 = cputime();
		    storageTime = (t2 - t1)*iCPS;
                } 

                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);	    

		    return(dictMyDS.search(loWord) || dictMyDS.search(upWord));    
		}

};

