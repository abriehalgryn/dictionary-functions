#ifndef TRIGRAM_H
#define TRIGRAM_H

#include <unordered_map>
#include<string>
#include <vector>
#include "Word.h"
#include "Dictionary_Part02.h"



using namespace std;

class trigram
{
private:
	string file_contents;
	unordered_map<string, unordered_map<string, int>> chances;
	unordered_map<string, unordered_map<string, float>> chances_percent;
	unordered_map<string, int> total;

public:
	void loadTextFile();
	void calculatePercentages();
	void displayTopThree();
	string weightedChance(string random_key);
	void generateRandomWords(Dictionary_Part02 dict);
	int getChoice();
	void displayMenu();
	string convertLower(string& s);
	bool searchForWord(string search, vector<Word> wordVector);
};

#endif