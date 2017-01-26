// Gustavo J. Munoz
// Assignment 4 - Binary Search Tree
// dictionary.h

#include <fstream>
#include <set>
#include <list>
#include "MRBST.h"
#include <locale>
#include <algorithm>

using namespace std;

// Using <set> STL ------------------------------------------------------------------------------------
class Dictionary{

        public:
		set<string> dictSet; 			
		locale loc;
		string fileLoc;
		
                Dictionary(string fileLocation){	
		    fileLoc = fileLocation;
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
                }
               
                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		    return((dictSet.find(loWord) != dictSet.end()) || (dictSet.find(upWord) != dictSet.end()));    
		}
};

// Using <list> STL ------------------------------------------------------------------------------------
class DictionaryLL{
        public:
		list<string> dictLL; 			
		locale loc;
		string fileLoc;
		
                DictionaryLL(string fileLocation){	
		    fileLoc = fileLocation;
		    fstream ifs(fileLocation.c_str(), fstream::in);	
		    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictLL.insert(dictLL.end(), str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
		}

                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		  //return((dictLL.find(loWord) != dictLL.end()) || (dictLL.find(upWord) != dictLL.end()));    
		  
		    list<string>::iterator pos;
		    list<string>::iterator pos2;
		    
		    pos = find(dictLL.begin(), dictLL.end(), loWord);
		    pos2 = find(dictLL.begin(), dictLL.end(), upWord);
		    
		    if(pos != dictLL.end() || pos2 != dictLL.end()){
			return true;
		    }
		    else{
		       return false;
		    }
		}
};

// Using MRBST ----------------------------------------------------------------------------------------
class DictionaryMRBST{

        public:
		MRBST<string> dictMRBST; 			
		locale loc;
		string fileLoc;
		
                DictionaryMRBST(string fileLocation){	
		    fileLoc = fileLocation;
		    fstream ifs(fileLocation.c_str(), fstream::in);	
					    
		    if(ifs.is_open()){
			string str;								  
			while (ifs >> str){
			dictMRBST.push(str);
			}
			ifs.close();
		    }
		    else{
			cout << "Error could not open file\n";
		    }
                } 

                bool search(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		    return(dictMRBST.search(loWord) || dictMRBST.search(upWord));    
		}

};

