// Dictionary_Part01.h

#ifndef DICTIONARYPART01_H
#define DICTIONARYPART01_H

#include <iostream>
#include<string>
#include <vector>
#include "Word.h"

//incudes the neccesary modules for this program to work
using namespace std;


//creates a class called Dictionary_Part01 as per assignment requriements
class Dictionary_Part01
{

protected:
	// sets appropriate fields
	//this vector wordVector will store all the word objects that will be loaded in from the txt.
	vector<Word> wordVector;


public:
	string convertLower(string& s);
	void loadDictionary();
	void displayName(string type, string name);
	void checkType(string type);
	void searchForWord();
	void moreThanThreeZs();
	void qWithNoU();
	void clearScreen();
	void displayMenu();
	int getChoice();
};

#endif