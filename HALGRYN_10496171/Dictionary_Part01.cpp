// Dictionary_Part01.cpp

#include <iostream>
#include<string>
#include <vector>
#include <sstream>  
#include <iomanip>
#include <fstream>
#include "Word.h"
#include "Dictionary_Part01.h"
#include <algorithm>




//this method converts a whole string to lowercase for error checking purposes
	//as the dictionary.txt contains proper nouns that are capatalise it will make searching for the word hard, thus we use this
string Dictionary_Part01::convertLower(string& s)
{
	for (int i = 0; i < s.length(); i++) //for every character in the string s we use tolower() to convert it, returning s
	{
		s[i] = tolower(s[i]);
	}
	return(s);


}
//this method will load the dictionary.txt or any text file declared in fileName
void Dictionary_Part01::loadDictionary()
{
	string fileName = "dictionary2021.txt";
	cout << "Loading the dictionary file..." << endl;
	ifstream myFile(fileName); //sets ifstream myFile variable to the name of the declared file for furhter use
	cout << "" << endl;

	while (!myFile.eof()) //while the file has not reached end of file:
	{
		string word; //needed variables
		string definition;
		string empty;

		if (myFile.is_open()) //if the file is open do
		{

			getline(myFile, word); //first line is the word and type of the word object
			getline(myFile, definition);  //second line read in is the definition
			getline(myFile, empty); //third line is read in to allowing for the cycle to repeat



			//splits the definitions with a whitespace.
			//the text file has some definitions with a elaboration. actual definitions are seperated with ";  " note there are 2 spaces not 1.		
			//see printDef() method for an alternative way of doing this
			int index;
			string delimiter = ";  "; //delimiter is what has to be replaced
			while ((index = definition.find(delimiter)) != string::npos)
			{ //using .replace()
				definition.replace(index, delimiter.size(), "\n - "); //this will replace the ";  " with a new line and a " - " for formatting purposes.
			}




			string arr[2];
			int i = 0;
			stringstream ssin(word);  //this will take the word and type and split them into two variables

			while (ssin.good() && i < 2) //check whether state of stream is good
			{
				ssin >> arr[i];
				++i;
			}

			string nameLower = convertLower(arr[0]); // this will make sure that all words in the dictionary txt file are loaded in all lower case using the method above
			Word word(arr[0], arr[1], definition); //creates a new object given certain string values
			wordVector.push_back(word); //adds the new object to the wordVector

		}

		else
		{
			cout << "Unable to open file"; //if the file cannot be opened for some reason it will display this
			cout << "" << endl;
			system("pause");
			exit(1); //this will terminate the program from running further
		}
	}
}

//this method will check the type of a string and display words accordingly, accepts type and string 
void Dictionary_Part01::displayName(string type, string name)
{
	if (type == "[pn]") //if the type of the word is pn (proper noun)
	{
		name[0] = toupper(name[0]); //converts the first letter to uppercase as required by assignment
		cout << "Word: " << name << endl;
	}
	else cout << "Word: " << name << endl; //if its not a proper noun the word will just normally print
}


//this method checks the type of the word given a word
void Dictionary_Part01::checkType(string type)
{
	if (type == "[n]")
	{
		cout << "Type: Noun (n.)" << endl;
	}
	else if (type == "[v]")
	{
		cout << "Type: Verb (v.)" << endl;
	}
	else if (type == "[adv]")
	{
		cout << "Type: Adverb (adv.)" << endl;
	}
	else if (type == "[adj]")
	{
		cout << "Type: Adjective (adj.)" << endl;
	}
	else if (type == "[prep]")
	{
		cout << "Type: Preposition (prep.)" << endl;
	}
	else if (type == "[misc]")
	{
		cout << "Type: MiscWords (misc.)" << endl;
	}
	else if (type == "[pn]")
	{
		cout << "Type: Proper Noun (pn.)" << endl;
	}
	else if (type == "[n_and_v]")
	{
		cout << "Type: Noun And Verb (n.v.)" << endl;
	}
}

//this method will take a users input, search for that input and display details
void Dictionary_Part01::searchForWord()
{


	Word newWord; //stores local variable to be used
	Word* word;   //stores a pointer of a value
	string search;
	cout << "What word would you like to search for?: ";
	cin >> search;
	convertLower(search);


	bool foundWord = 0;  // to check if the word has been found
	for (int i = 0; i < wordVector.size(); i++) // this if statement will allow us to loop through every instance of the wordVector
	{
		word = &wordVector[i]; //this will set word to the current object of the wordVector, we use & to get the address of the element at i
		if (word->getName() == search) // if the word at the current vector object is the same as the entered word. Have to use word->getName() as it is a address.
		{
			foundWord = 1; //sets the bool value to true as we have found a word.
			cout << "" << endl;
			displayName(word->getType(), word->getName());  //uses the neccecary methods to display needed information.
			checkType(word->getType());
			newWord.printDef(word->getDefinition());
		}
	}
	if (foundWord == 0) //if this bool value is not true, it means we have not found a word
	{
		cout << "Word not found." << endl;
	}

}

// this method will search for items with more than three z's.
void Dictionary_Part01::moreThanThreeZs()
{
	string listOfWords; // this is where the words that have more than three z's will be stored.
	bool checkIfWords = 0;
	Word* word;  //stores a pointer of a value
	for (int iterateWord = 0; iterateWord < wordVector.size(); iterateWord++) //iterates through each object of the vector
	{
		word = &wordVector[iterateWord]; //this will set word to the current object of the wordVector, we use & to get the address of the element at iterateWord
		string wordToSearch = word->getName();  // sets the word to the current word at the vector object
		int count = 0; // this will count the amount of z's in a word
		for (int iterateLetter = 0; iterateLetter < wordToSearch.size(); iterateLetter++) //this iterates all the letters of the current word and sees of it haz any 's
		{
			if (wordToSearch[iterateLetter] == 'z')
			{
				count++; //increments for each z in a word
			}
		}

		if (count > 3) // if there are more than 3 z's in a word
		{
			checkIfWords = 1; // sets the bool value of checkIfWords to true indicating that there are words
			listOfWords += wordToSearch;  //adds the current word to a string
			listOfWords += ", ";  // adds a comma to the end of every word that is stored in the variable
		}
	}

	if (checkIfWords == 1) // if there are words that have more than 3 z's
	{
		cout << "The word(s) with more than three z's are: ";
		listOfWords.erase(listOfWords.length() - 2); // this deletes the last two characters (", ") from the string so that a comma is not after the last word
		cout << listOfWords << endl;
	}

	else cout << "There are no words with more than three z's." << endl; //if no words have more than 3 z's
}

//this method will count the amount of words that have a 'q' without a following 'u'
void Dictionary_Part01::qWithNoU()
{
	string listOfWords; // this will be the list where the words will be stored.
	bool checkIfWords = 0;
	Word* word; //stores a pointer of a value
	for (int iterateWord = 0; iterateWord < wordVector.size(); iterateWord++) //iterates through each object of the vector
	{
		word = &wordVector[iterateWord]; //this will set word to the current object of the wordVector, we use & to get the address of the element at iterateWord
		string wordToSearch = word->getName();
		for (int iterateLetter = 0; iterateLetter < wordToSearch.size(); iterateLetter++) //iterates through each letter of a word
			if (wordToSearch[iterateLetter] == 'q') //if there is a q in the word
			{
				int nextLetter = iterateLetter + 1; //sets the next letter (the one after q)
				if (wordToSearch[nextLetter] != 'u')//checks if this next letter is u
				{
					checkIfWords = 1; // sets the bool value of checkIfWords to true indicating that there are words
					listOfWords += wordToSearch;  //adds the current word to a string
					listOfWords += ", ";  // adds a comma to the end of every word that is stored in the variable
				}
			}
	}
	if (checkIfWords == 1) // Check if there are words that have a 'q' without a following 'u'
	{
		cout << "The words that have a 'q' without a following 'u' are: ";
		listOfWords.erase(listOfWords.length() - 2); // this deletes the last two characters (", ") from the string so that a comma is not after the last word
		cout << listOfWords << endl;
	}

	else cout << "There are no words that have a 'q' without a following 'u'." << endl;
}




//this method calls on system to clear the screen for formatting purposes
void Dictionary_Part01::clearScreen()
{
	system("pause");
	system("cls");
}


//this method will display a menu for he user.
void Dictionary_Part01::displayMenu()
{
	cout << "Welcome to the Dictioary. Please select one of the options below: [1, 2, 3, 4, 5, 6, 7] " << endl;
	cout << "1. Search for a word." << endl;
	cout << "2. Find the word(s) with more than three z's." << endl;
	cout << "3. List the words that have a 'q' without a following 'u' eg. 'Iraqi." << endl;
	cout << "4. List all words that are a noun and a verb e.g. 'Phone'" << endl;
	cout << "5. List all words that are palindromes. e.g 'civic'" << endl;
	cout << "6. Report all words that are anagrams of a specific word. " << endl;
	cout << "7. Play the guessing game!" << endl;
	cout << "8. Have fun with trigrams!" << endl;
	cout << "9. Exit." << endl;
	cout << "Choice: ";
}

//this method is used for error checking if the input is supposed to be a int
int Dictionary_Part01::getChoice()
{
	Dictionary_Part01 newDictionary;
	int choice = 0;
	newDictionary.displayMenu();
	cin >> choice;

	while (!cin.good())
	{
		cout << "Invalid input, please try again." << endl;
		newDictionary.clearScreen();

		//clear system
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		newDictionary.displayMenu();
		cin >> choice;
	}
	//clear system
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return choice;
}

