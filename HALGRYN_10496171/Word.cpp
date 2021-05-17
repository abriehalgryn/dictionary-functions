// Word.cpp

#include <iostream>
#include<string>
#include <fstream>
#include "Word.h"


string Word::getName()
{
	return name;
}

string Word::getType()
{
	return type;
}

string Word::getDefinition()
{
	return definition;
}


//this method prints the definition as required for basic task one. The definition is loaded into the wordVector already formatted so all it has to do is print it.
void Word::printDef(string definition)
{
	cout << "Definition(s):" << endl;
	cout << " - " << definition << endl; //formatting for the first instance of definition
	cout << "" << endl;
	/*
	cout << "Definition(s): ";
	cout << "" << endl;

	bool lineStart = true;  //flag that tells whether it's  the beginning of a line
	for (int i = 0; i < definition.length(); i++) {
		if (lineStart) {
			if (definition[i] == ' ') continue;  //if it's the beginning of a line (lineStart), and the character is whitespace, then ignore it
			else {                               //if its the beginning of a line and the character isn't whitespace, print it out and also set the flag to false
												//cout out every character until we find a semi colon
				lineStart = false;
				cout << definition[i];                              //as the dictionary.txt file is very inconsistant, this code will print every definition
																	//given that each ";" completely seperates the definiton.
			}
		}
		else {                                 //when we find ";", we shit out a newline and reset the flag to true since we are at the beginning of a line
			if (definition[i] == ';') {
				lineStart = true;
				cout << endl;
			}
			else cout << definition[i];
		}
	}

	cout << "" << endl;
	*/
}
