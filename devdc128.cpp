#include <bits/stdc++.h>
using namespace std;

/*
Write a function that determines the score of a hand in a standard game of Blackjack 21.
The function will receive an array of strings representing the cards that are
in the hand of the player. Please return the score of the hand as an integer.

Scoring:
Number cards count as their face values. Royalty count as 10s. An Ace can be either 11 or 1.

Return the score closest to 21. If the score is greater than 21, return the score and say "Busted!".

Test cases:

["A"]
["A", "J"]
["A", "10", "A"]
["5", "3", "7"]
["5", "4", "3", "2", "A", "K"] 
*/

int score(vector<string> cards){
	int score = 0;
	unordered_set<string> royalty = {"Q", "K", "J"};
	int aceCount = 0;
	
	for(string card : cards){
		if(card == "A"){
			score += 11;
			aceCount++;
		}
		else if(royalty.find(card) != royalty.end())
			score += 10;
		else
			score += stoi(card);
	}
	
	if(score <= 21)
		return score;
	
	while(score>21 && aceCount){
		score -= 10;
		aceCount--;
	}
	cout << "Busted\n";
	return score;
}

void testFunc(vector<vector<string>> v){
	for(auto cards : v)
		cout << score(cards) << "\n";
}

// main function
int main(){
	testFunc({
		{"A"},
		{"A", "J"},
		{"A", "10", "A"},
		{"5", "3", "7"},
		{"5", "4", "3", "2", "A", "K"}
	});
	return 0;
}