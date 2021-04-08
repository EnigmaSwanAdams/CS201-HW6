/*
* Enigma Swan Adams
* CS201-HW6
* 4/7/21
* 
* file name: hangman.cpp
* Additional program 1 as described in the homework assignment on blackbuard
* calling the function hangman() from main runs the full Additional 1 program
*
*/

#include "hangman.h"
#include <algorithm>
#include<iostream>
#include <vector>
#include<map>
#include<iterator>


using std::vector; using std::string;
using std::endl; using std::cout; using std::cin;
using std::map;
using std::begin; using std::end;
using std::find;

int main() {
	hangman("what");
	return 0;
}
/*requirments: play hangman, and 
//Assign words they will be guessing at
//ten chances to guess the right word
//keep tract of all the letters currently used *****************************/
void hangman(string word) {
	
	std::transform(word.begin(), word.end(), word.begin(), tolower);

	//intital promt
	cout << "Lets play a game of hangman. You have ten body parts." << endl;

	//map to store the letters guessed connected to how many letters total guessed
	map<char, size_t> guessed;
	//map to store body parts connected to how many wrong letters guessed
	map <int, string> bodyParts = {
		{1, "head"},
		{2, "body"},
		{3, "right arm"},
		{4, "left arm"},
		{5, "right leg"},
		{6, "left leg"},
		{7, "right hand"},
		{8, "left hand"},
		{9, "right foot"},
		{10, "left foot"}
	};

	int numGuesses = 0;
	int numWrongGuesses = 0;
	int rightGuesses = 0;

		while (numWrongGuesses < 10) {
			//get user input
			cout << "Enter a single letter "; // continueing prompt
			char guess;
			cin >> guess;
			guess = tolower(guess);

			numGuesses++;

			//see if they were right
			int numLetters = count(word.begin(), word.end(), guess);
			

			if (numLetters == 0) {
				cout << "Sorry that letter isn't in the word" << endl;
				numWrongGuesses++;
				cout << "Imagine I'm drawing a " << bodyParts[numWrongGuesses] << "\nYou have " <<
					10-numWrongGuesses << " wrong guesses left." << endl;

			}
			else if (guessed.count(guess) > 0) { // lets the user know if they entered that letter befor
				cout << "You've guessed that befor. No penalty, but try again." << endl;

			}
			else {
				cout << "You guessed right. There are " << numLetters << " " << guess << "(s)" << endl;
				//only increment right guesses if they guessed a new letter 
				rightGuesses = rightGuesses + numLetters;

				guessed[guess] = numGuesses;
			}
			
			//check if they have guessed all the letters in the word
			if (rightGuesses >= word.size()) {
				cout << "You guessed all the letters! \n"
					"The word was " << word << endl;
				break;
			}

	}
}
