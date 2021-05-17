#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "trigram.h"
#include <sstream>  
#include "Dictionary_Part02.h"

using namespace std;



string trigram::convertLower(string& s)
{
	for (int i = 0; i < s.length(); i++) //for every character in the string s we use tolower() to convert it, returning s
	{
		s[i] = tolower(s[i]);
	}
	return(s);


}

bool trigram::searchForWord(string search, vector<Word> wordVector)
{


	Word newWord; //stores local variable to be used
	Word* word;   //stores a pointer of a value


	bool foundWord = 0;  // to check if the word has been found
	for (int i = 0; i < wordVector.size(); i++) // this if statement will allow us to loop through every instance of the wordVector
	{
		word = &wordVector[i]; //this will set word to the current object of the wordVector, we use & to get the address of the element at i
		if (word->getName() == search) // if the word at the current vector object is the same as the entered word. Have to use word->getName() as it is a address.
		{
			foundWord = 1; //sets the bool value to true as we have found a word.
		}
	}
	if (foundWord == 0) //if this bool value is not true, it means we have not found a word
	{
		return false;
	}
	else
	{
		return true;
	}


}


void trigram::loadTextFile()
{
	cout << "Loading Text File..." << endl;
	cout << " " << endl;
	string get_contents;
	ifstream in_file;
	string file_name = "dictionary2021.txt"; // loads text file
	in_file.open(file_name);
	while (!in_file.eof()) // to get you all the lines.
	{
		getline(in_file, get_contents); // saves the line in file_contents and adds a space to seperate lines
		file_contents += get_contents + " ";
	}
	in_file.close();

	file_contents = convertLower(file_contents); // converts file contents to lowercase


}

void trigram::calculatePercentages()
{
	cout << "Calculating Percentages..." << endl;
	cout << " " << endl;
	int count = 0;
	const char* check_for_blank = " ";

	for (int i = 0; i < file_contents.length(); i++) // loopps for the length of the file contents
	{
		string string_search;
		string_search += file_contents[i];
		string_search += file_contents[i + 1];
		string test = string(1, file_contents[i + 2]); // sets every 2 chars to add to the needed maps
		string next_char = test;

		// if the last character is not a space
		if (string_search[1] != *check_for_blank)
		{

			//adds 1 to the total of `two characters` if it is in the map, if not it adds it to the map
			if (total.find(string_search) == total.end())
			{
				total[string_search] = 0;
			}
			total[string_search] += 1;

			// adds the `two characters` `next character` and `count of next character` to chances map
			if (chances.find(string_search) == chances.end())
			{
				unordered_map<string, int> emptyMap;
				chances[string_search] = emptyMap;
			}

			if (chances[string_search].find(next_char) == chances[string_search].end())
			{
				chances[string_search][next_char] = 0;
			}

			chances[string_search][next_char] += 1;

		}
	}

	// calls a_map.begin() and a_map.end()
	//calculation of percantage to store
	for (auto it = chances.begin(); it != chances.end(); ++it)
	{
		string string_search = it->first;

		for (auto it = chances[string_search].begin(); it != chances[string_search].end(); ++it)
		{
			string next_char = it->first;
			int count = it->second;

			float seach_char_total = chances[string_search][next_char];
			float search_string_total = total[string_search];

			chances_percent[string_search][next_char] += seach_char_total / search_string_total;
		}
	}

}
// displays the top 3 chances
void trigram::displayTopThree()
{
	string user_input;
	while (true)
	{
		cout << "Enter two characters: ";
		getline(cin, user_input);
		const char* check_for_blank = " ";

		user_input = convertLower(user_input);

		if (user_input.length() != 2) // if the length of the user input is not 2 invalid input
		{
			cout << "Invalid input, Please enter 2 characters only." << endl;
		}
		else if (user_input[1] == *check_for_blank) // if the last character of user input is blank
		{
			cout << "The second character cannot be a space." << endl;
		}

		else
		{
			break;
		}
	}


	string highest;
	string second_highest;
	string third_highest;

	for (char l = 'a'; l <= 'z'; ++l) // for each character in the alphabet
	{
		string character_of_alphabet(1, l);
		float current_percent = chances_percent[user_input][character_of_alphabet];

		// compare the current percent to the user input to see which one is higest
		if (current_percent > chances_percent[user_input][highest])
		{
			third_highest = second_highest;
			second_highest = highest;
			highest = character_of_alphabet;
		}
		else if (current_percent > chances_percent[user_input][second_highest])
		{
			third_highest = second_highest;
			second_highest = character_of_alphabet;
		}
		else if (current_percent > chances_percent[user_input][third_highest])
		{
			third_highest = character_of_alphabet;
		}
	}
	// prints a rounded percentage
	cout << "'" << highest << "' Has a " << roundf((chances_percent[user_input][highest] * 100) * 100) / 100 << "% Chance of coming after '" << user_input << "'" << endl;
	cout << "'" << second_highest << "' Has a " << roundf((chances_percent[user_input][second_highest] * 100) * 100) / 100 << "% Chance of coming after '" << user_input << "'" << endl;
	cout << "'" << third_highest << "' Has a " << roundf((chances_percent[user_input][third_highest] * 100) * 100) / 100 << "% Chance of coming after '" << user_input << "'" << endl;
}

string trigram::weightedChance(string random_key)
{
	float randomNum = ((float)rand() / RAND_MAX); // gets a random float from 0 to 1
	for (auto& it : chances_percent[random_key]) // goes through chances_percent
	{
		string current_element = it.first;
		float option_chance = chances_percent[random_key][current_element]; // uses the current "random_key" to get the current chance of element

		if (randomNum <= option_chance) // if the random number is  less than the option chance
		{
			return current_element; // that will be the current element
		}

		else
		{
			randomNum -= option_chance;
		}
	}

}


void trigram::generateRandomWords(Dictionary_Part02 dict) //generate 10 random words thats not in the dict
{

	vector<Word>* wordVector;// setter for wordVector
	wordVector = dict.getVector();

	const int max_word_length = 10; // settings for generating words
	const int min_word_length = 4;
	const int amount_of_words = 10;
	const bool real_words = 0;


	list<string> words_to_generate; // where the generated words will be stored
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	srand((unsigned)time(NULL)); // seed for random

	for (int i = amount_of_words; i != words_to_generate.size();) // loop will run till amount_of_words words has been added to "words to generate"
	{
		string random_character = string(1, alphabet[rand() % 26]); // select a random character from the alphabet to mark the "start of the word"
		string random_key = " " + random_character; // adds the random alphabet character to random key to start the word
		string word_to_add = random_key; // stores the beginning of the word

		int word_length = rand() % max_word_length + 1; // sets a length for the word based on max_word_length (+1 as there is a space)
		while (word_to_add.length() <= word_length)
		{
			string letter_to_add = weightedChance(random_key); // using the weighted chance to add a letter the the word
			if (isalpha(letter_to_add[0]))
			{
				word_to_add += letter_to_add;
				random_key[0] = random_key[1]; // resets random_key to the most recent 2 chars
				random_key[1] = letter_to_add[0];
			}

		}
		word_to_add.substr(1);
		word_to_add.replace(0, 1, ""); // removes the space infront of word_to_add
		if (word_to_add.length() >= min_word_length && searchForWord(word_to_add, *wordVector) == real_words) // adds the word if it is >= min word length and not a real word
		{
			if (find(begin(words_to_generate), end(words_to_generate), word_to_add) == end(words_to_generate)) // checks if the word has already been added
			{
				words_to_generate.push_back(word_to_add);

			}
		}

	}
	int count = 0;
	cout << "The " << amount_of_words << " randomly generated words are:" << endl; // displayes the words
	for (auto v : words_to_generate)
	{
		count += 1;
		cout << count << ". ";
		cout << v << endl;
	}

}


//this method is used for error checking if the input is supposed to be a int
int trigram::getChoice()
{
	trigram new_trigram;
	Dictionary_Part01 newDictionary;
	int choice = 0;
	new_trigram.displayMenu();
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

void trigram::displayMenu() // display the menu
{
	cout << "Welcome to the Advanced Task!! Please select one of the options below: [1, 2, 3]" << endl;
	cout << "1. Calculate the probability of any character occurring after any combination of two characters." << endl;
	cout << "2. Generate 10 random words which sound like English words, but do not exist in the dictionary." << endl;
	cout << "3. Go back to main program." << endl;
	cout << "Choice: ";
}