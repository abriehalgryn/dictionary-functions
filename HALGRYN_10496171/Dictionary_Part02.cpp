// Dictionary_Part01.cpp

#include <iostream>
#include<string>
#include <vector>
#include <sstream>  
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"



void Dictionary_Part02::nounAndVerb()
{
	Word* word;   //stores a pointer of a value
	string listOfWords; // this will be the list where the words will be stored.
	bool checkIfWords = 0;
	for (int i = 0; i < wordVector.size(); i++) // this if statement will allow us to loop through every instance of the wordVector
	{
		word = &wordVector[i]; //this will set word to the current object of the wordVector, we use & to get the address of the element at i
		 //this will set "word" to the current object of the wordVector, we use & to get the address of the element at iterateWord
		string typeToSearch = word->getType();
		if (typeToSearch == "[n_and_v]")
		{
			checkIfWords = 1; // sets the bool value of checkIfWords to true indicating that there are words
			listOfWords += word->getName();  //adds the current word to a string
			listOfWords += ", ";  // adds a comma to the end of every word that is stored in the variable
		}
	}
	if (checkIfWords == 1) // Check if there are words that are a nound and a verb
	{
		cout << "The words that are a nound and a verb are: ";
		listOfWords.erase(listOfWords.length() - 2); // this deletes the last two characters (", ") from the string so that a comma is not after the last word
		cout << listOfWords << endl;
	}

	else cout << "There are no words that are a nound and a verb." << endl;
}


void Dictionary_Part02::checkForPalindromes()
{
	string listOfWords; // this will be the list where the words will be stored.
	bool checkIfWords = 0;
	Word* word; //stores a pointer of a value
	for (int i = 0; i < wordVector.size(); i++) //iterates through each object of the vector
	{
		word = &wordVector[i];
		string wordToSearch = word->getName();

		int length = wordToSearch.length();
		bool isPalindrome = true; // sets a ispalindrome variable to later check if one of the words are a palindrome
		for (int i = 0; i < (length / 2); i++)
		{
			if (wordToSearch[i] != wordToSearch[(length - 1) - i]) // if the word is not a palindrome (comparing the fist and last chat for the size of half of the word)
				isPalindrome = false;
		}

		if (isPalindrome == true) // if the word is a palindrome
		{
			checkIfWords = 1; // sets the bool value of checkIfWords to true indicating that there are words
			listOfWords += word->getName();  //adds the current word to a string
			listOfWords += ", ";  // adds a comma to the end of every word that is stored in the variable
		}

	}
	if (checkIfWords == 1) // Check if there are words that are a palindromes
	{
		cout << "The words that are palindromes: ";
		listOfWords.erase(listOfWords.length() - 2); // this deletes the last two characters (", ") from the string so that a comma is not after the last word
		cout << listOfWords << endl;
	}

	else cout << "There are no words that are palindromes." << endl;
}


void Dictionary_Part02::checkForAnagram()
{

	string listOfWords; // this will be the list where the anagrams will be stored.
	bool checkIfWords = 0; // this will be used as a check for if there are anagrams
	Word* word; //stores a pointer of a value

	string anagramToSearch = ""; // this will be where the user input will be stored for comparison
	cout << "What word would you like to search for: ";
	cin >> anagramToSearch;
	anagramToSearch = convertLower(anagramToSearch);
	string storeWord = anagramToSearch;
	int anagramSearch = anagramToSearch.length();

	for (int i = 0; i < wordVector.size(); i++) //iterates through each object of the vector
	{
		word = &wordVector[i];
		string wordToSearch = word->getName();
		int lengthOfSearching = wordToSearch.length();
		bool isAnagram = true; // sets a isanagram variable to later check if one of the words are a anagram

		if (anagramSearch != lengthOfSearching)// if the string sizes dont match they cannot be anagrams
		{
			isAnagram = false;
		}

		sort(wordToSearch.begin(), wordToSearch.end()); // sort both the strings to compare
		sort(anagramToSearch.begin(), anagramToSearch.end());

		for (int i = 0; i < anagramSearch; i++)// compare both strings to see if they are anagrams
			if (wordToSearch[i] != anagramToSearch[i])
				isAnagram = false;

		if (isAnagram == true) // if the word is a anagram
		{
			checkIfWords = 1; // sets the bool value of checkIfWords to true indicating that there are words
			listOfWords += word->getName();  //adds the current word to a string
			listOfWords += ", ";  // adds a comma to the end of every word that is stored in the variable
		}
	}

	if (checkIfWords == 1) // Check if there are words that are a anagrams
	{
		cout << "The words that are a anagram of '" << storeWord << "' are: ";
		listOfWords.erase(listOfWords.length() - 2); // this deletes the last two characters (", ") from the string so that a comma is not after the last word
		cout << listOfWords << endl;
	}

	else cout << "There are no words that are a anagram of '" << storeWord << "'" << endl;

}


void Dictionary_Part02::guessingGame()
{
	Word newWord;
	string listOfWords; // this will be the list where the anagrams will be stored.
	bool checkIfWords = 0; // this will be used as a check for if there are anagrams
	Word* word; //stores a pointer of a value
	int lives = 3;

	cout << "" << endl;
	cout << "Welcome to the Guessing Game!" << endl; // printing menu and rules for the game
	cout << "You will be presented with the definition of a random noun and the length of that noun." << endl;
	cout << "You have three attempts to guess this noun. The more guesses you fail, the more hints you will get." << endl;
	cout << "You have " << lives << " live(s) remaining." << endl;
	cout << "" << endl;


	vector<Word> nounVector; // create a vector to store all the word objects that are nouns
	for (int i = 0; i < wordVector.size(); i++)// iterates through each object of the vector
	{
		word = &wordVector[i];
		string typeToSearch = word->getType();
		if (typeToSearch == "[n]")
		{
			nounVector.push_back(*word); // adds the noun object to the word vector
		}
	}

	srand((unsigned)time(NULL)); // using time to create a more "random" intiger to use to select a random definition
	int randomWord = rand() % nounVector.size();

	word = &nounVector[randomWord]; // sets the current object to the random int
	string wordToSearch = word->getName(); // get name and definiton for the game
	int lengthOfWord = wordToSearch.length();
	cout << "Length: " << lengthOfWord << endl; // print the definition and the length of the word
	newWord.printDef(word->getDefinition());


	string hint = ""; // variables so that we can print hints for the player
	int wordChar = 0;

	while (lives != 0) // loop will run as long as the user is not out of "lives"
	{
		string guess;
		cout << "Guess: ";
		cin >> guess;
		guess = convertLower(guess);

		if (guess != wordToSearch) // if the user guess is incorrect
		{
			hint += wordToSearch[wordChar]; // adds a char to hint for display
			wordChar += 1;


			lives -= 1; // takes a life away
			cout << "Incorrect!" << endl;
			cout << "" << endl;
			if (lives != 0) // if the user still has lives
			{
				cout << "A letter as been revealed!: " << hint << endl; // print the revealed letter and the amount of lives left
				cout << "You have " << lives << " live(s) remaining." << endl;
				cout << "" << endl;
			}
			else
			{
				cout << "Oh no! You have lost :(" << endl; // when they have lost reveal the word
				cout << "The correct word was: " << wordToSearch << endl;
			}

		}

		else if (guess == wordToSearch) // if the player guessed the word print that they win!
		{
			cout << "You guessed it!" << endl;
			cout << "You win!... nothing" << endl;
			lives = 0;
		}
	}
}

vector<Word>* Dictionary_Part02::getVector()
{
	vector<Word>* pointer;
	pointer = &wordVector;
	return pointer; // getter for wordVector
}