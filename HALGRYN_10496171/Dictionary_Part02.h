// Dictionary_Part02.h

#ifndef DICTIONARYPART02_H
#define DICTIONARYPART02_H

#include <iostream>
#include<string>
#include <vector>
#include "Word.h"
#include "Dictionary_Part01.h"

//incudes the neccesary modules for this program to work
using namespace std;


//creates a class called Dictionary_Part01 as per assignment requriements
class Dictionary_Part02 : public Dictionary_Part01
{
protected:
	// sets appropriate fields


public:
	// the following functions accept the newdictionary object so that the loaded vector can be used
	void nounAndVerb();
	void checkForPalindromes();
	void checkForAnagram();
	void guessingGame();
	vector<Word>* getVector();
};

#endif