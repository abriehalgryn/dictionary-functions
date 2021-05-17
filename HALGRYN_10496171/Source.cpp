// Source.cpp
// CSP2104 - OOC++
// Assignment 1 Deliverable 1
// Abrie Halgryn - 10496171

#include <iostream>
#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"
#include "trigram.h"

using namespace std;

//main of the function
int main()
{
	Dictionary_Part02 newDictionary;
	newDictionary.loadDictionary(); //loads dictionary
	
	trigram new_trigram;
	new_trigram.loadTextFile(); // loads the desired textfile
	new_trigram.calculatePercentages(); // calculates percentages based on the desired text file


	bool loop = 1;
	while (loop) //while loop to be able to return to the main menu once a task has been excecuted
	{

		int choice = newDictionary.getChoice(); //this is used for error checking.

		if (choice == 1)
		{
			newDictionary.searchForWord(); //Search for a word
			newDictionary.clearScreen(); // clear screen

		}

		else if (choice == 2)
		{
			newDictionary.moreThanThreeZs(); //Find the word(s) with more than three z's."
			newDictionary.clearScreen();
		}

		else if (choice == 3)
		{
			newDictionary.qWithNoU(); //List the words that have a 'q' without a following 'u' eg. 'Iraqi."
			newDictionary.clearScreen();
		}

		else if (choice == 4)
		{
			newDictionary.nounAndVerb(); // the following functions accept the newdictionary object so that the loaded vector can be used
			newDictionary.clearScreen();
		}

		else if (choice == 5)
		{
			newDictionary.checkForPalindromes();
			newDictionary.clearScreen();
		}

		else if (choice == 6)
		{
			newDictionary.checkForAnagram();
			newDictionary.clearScreen();
		}

		else if (choice == 7)
		{
			newDictionary.guessingGame();
			newDictionary.clearScreen();
		}


		else if (choice == 8) // if the user whishes to have fun with trigram
		{
			bool loop = 1;
			while (loop) //while loop to be able to return to the main menu once a task has been excecuted
			{
				int choice = new_trigram.getChoice(); //this is used for error checking.

				if (choice == 1)
				{
					new_trigram.displayTopThree(); // display top three letter combinations based on a input
					newDictionary.clearScreen(); // clear screen

				}

				else if (choice == 2)
				{
					new_trigram.generateRandomWords(newDictionary); // generate random words" << accepts newdictionary object to have access to the wordvector
					newDictionary.clearScreen();
				}

				else if (choice == 3) // if the user whishes to quit the program.
				{
					loop = 0;
					newDictionary.clearScreen();
				}

				else
				{
					cout << "Invalid input, please try again." << endl;
					newDictionary.clearScreen();
					choice = new_trigram.getChoice();
				}
			}
		}

		else if (choice == 9) // if the user whishes to quit the program.
		{
			cout << "Goodbye" << endl;
			loop = 0;
			newDictionary.clearScreen();
		}

		else
		{
			cout << "Invalid input, please try again." << endl;
			newDictionary.clearScreen();
			choice = newDictionary.getChoice();
		}



	}
	return 0;
}
