#include <bits/stdc++.h>
using namespace std;

/*

Everyone loves a game of Scrabble!
Your challenge today is to calculate the scrabble score of a given word.

A   => 1, B   => 3,  C   => 3, D   => 2, E   => 1,
F   => 4, G   => 2,  H   => 4, I   => 1, J   => 8,
K   => 5, L   => 1,  M   => 3, N   => 1, O   => 1,
P   => 3, Q   => 10, R   => 1, S   => 1, T   => 1,
U   => 1, V   => 4,  W   => 4, X   => 8, Y   => 4,
Z   => 10,

Double letter (doubles the value of the letter)
-A double letter will be represented with an asterisk after the letter. he*llo would make a double letter on the e.

Triple letter (triples the value of the letter)
-A triple letter will be represented with two asterisks after the letter. he**llo would make a triple letter on the e.

Double word (double the value of the word after letter rules have been applied)
-A double word is represented by the word ending in (d)

Triple word (triple the value of the word after letter rules have been applied)
-A triple word is represented by the word ending in (t)

A blank (the letter given will score 0)
-A blank tile will be represented with a caret after the letter or
asterisk if the letter has a double or triple letter value. he^llo would mean the e scores 0.

Bonus 50!
-If the word is a seven letter word an additional 50 points are awarded.

*/

int score(string s){
	unordered_map<char, int> scoreMap = 
	{
		{'A', 1},{'B', 3}, {'C', 3}, {'D', 2}, {'E',1}, {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8},
		{'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1},
		{'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}
	};
	int length = 0;
	int score = 0;
	int currentLetterCount = 0;
	int currentLetterScore = 0;
	char lastLetter;
	for(int i=0;i<s.length();i++){
		if(s[i] == '*'){
			if(s[i-1] != '*'){
				score += currentLetterScore;
				currentLetterCount = 2;
			}
			else{
				score += currentLetterScore;
				currentLetterCount = 3;
			}
		}
		else if(s[i] == '^'){
			score -= (currentLetterScore*currentLetterCount);
		}
		else{
			currentLetterScore = scoreMap[s[i]];
			lastLetter = s[i];
			currentLetterCount = 1;
			score += currentLetterScore;
			length++;
		}
	}
	if(length == 7)
		score += 50;
	if(lastLetter == 'D')
		score *= 2;
	if(lastLetter == 'T')
		score *= 3;
	return score;
}

// main function
int main(){
	string s = "HE**^LLO";
	cout << score(s) << "\n";
	return 0;
}