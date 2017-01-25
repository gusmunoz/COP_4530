// Gustavo J. Munoz                        
// Assignment 1 - Spell Checker
// Header File

#ifndef DICTIONARY_1
#define DICTIONARY_1


#include <fstream>
#include <locale>
#include <string>
#include "LinkedList.h"

using namespace std;

class Dictionary{

        public:
		LinkedList dictLL; 			
		locale loc;
		string fileLoc;
		double timeInSeconds;
		
                Dictionary(string fileLocation){	
		    fileLoc = fileLocation;
		    fstream ifs(fileLocation.c_str(), fstream::in);	
		    
		    clock_t startTime = clock();			//starting timer
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
		    clock_t endTime = clock();			//end timer
		    clock_t clockTicksTaken = endTime - startTime;
		    timeInSeconds = clockTicksTaken/(double) CLOCKS_PER_SEC;               
		  
		} 
                
                void printSelf(){					//print to screen dictionary word
		    for(LinkedList::iterator it = dictLL.begin(); it!=dictLL.end(); it++){
			cout << *it << endl;
		    }
                }
                
                void printFirstThree(){                       		//print to screen dictionary word
		    LinkedList::iterator it = dictLL.begin();
		    for(int i = 0; i < 3; i++){
			cout << *it << endl;
		    }
		}
		
                bool match(string word){
		    string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		    string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		    return((dictLL.find(loWord) != dictLL.end()) || (dictLL.find(upWord) != dictLL.end()));    
		}
		
		void addWord(string word){
		    dictLL.insert(dictLL.end(), word);
		}
		
		void dump(){
		    fstream tmp(string(fileLoc).c_str(), fstream::out);
		    for(LinkedList::iterator it=dictLL.begin(); it!=dictLL.end();it++){
			tmp << *it << " ";
		    }
		}
		
// 		//word must have occured 4 times in inputFile to call this guy
// 		bool organize(string& word) {
// 		 return dictLL.move(word); 
// 		}

};

#endif
