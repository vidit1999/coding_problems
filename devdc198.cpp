#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that determines the score of a hand in the card game 21 Blackjack.

The function will receive an array filled with strings that represent each card in the hand.
Your function should return the score of the hand as an integer.

Number cards count as their face value (2 through 10). Jack, Queen and King count as 10.
An Ace can be counted as either 1 or 11.

Return the highest score of the cards that is less than or equal to 21.
If there is no score less than or equal to 21 return the smallest score more than 21.

Examples
["A"] ==> 11
["5", "4", "3", "2", "A", "K"] ==> 25

Tests
["A", "J"]

["A", "10", "A"]

["5", "3", "7"]
*/

int scoreHand(vector<string> cards){
    unordered_map<string,int> scoreCount; // holds the score of each card
    for(int i=2;i<=10;i++){
        scoreCount[to_string(i)] = i;
    }
    scoreCount["A"] = 1; // store the score of A as 1 (minimum)
    scoreCount["J"] = 10;
    scoreCount["K"] = 10;
    scoreCount["Q"] = 10;

    unordered_map<string, int> cardCount; // holds the number of times cards are apperaing
    int score = 0; // minimum score (i.e. score with A as 1)
    for(string s : cards){
        score += scoreCount[s];
        cardCount[s]++;
    }
    
    // if score is 21 return 21
    if(score == 21)
        return score;
    
    // if score < 21 try to maximize it
    // but keep it less than or equal to 21
    if(score < 21){
        for(int i=0;i<cardCount["A"];i++){
            if(score > 11){
                return score;
            }
            // add score of A to score
            // score = score - 1 + 11
            score += 10;
        }
    }

    // no need to write the case when score > 21
    // because we are always starting from minimum score possible
    return score;
}

// main function
int main(){
    cout << scoreHand({"A"}) << "\n";
    cout << scoreHand({"5", "4", "3", "2", "A", "K"}) << "\n";
    cout << scoreHand({"A", "J"}) << "\n";
    cout << scoreHand({"A", "10", "A"}) << "\n";
    cout << scoreHand({"5", "3", "7"}) << "\n";
    cout << scoreHand({"5", "5", "A"}) << "\n";
    cout << scoreHand({"A", "A", "A"}) << "\n";
    cout << scoreHand({"A", "A"}) << "\n";
    cout << scoreHand({"5", "4", "3", "10", "K"}) << "\n";
    return 0;
}