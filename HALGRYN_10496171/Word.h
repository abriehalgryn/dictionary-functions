//Word.h

#ifndef WORD_H
#define WORD_H

#include<string>

using namespace std;

//creates a class called Word
class Word
{
private: // sets appropriate fields
	string name;
	string type;
	string definition;

public:
	Word() {}; // default constructor(s)

	Word(string name, string type, string definition)
	{
		this->name = name;
		this->type = type;
		this->definition = definition;
	}

	string getName();
	string getType();
	string getDefinition();
	void printDef(string definition);

	//these are getters for name, definition and type as they are normally "private"

};

#endif