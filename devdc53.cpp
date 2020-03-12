#include <bits/stdc++.h>
using namespace std;

/*
To faro shuffle a deck of playing cards is to split the deck exactly in half,
then perfectly interweave the cards, such that the original top and bottom cards are unchanged.

Write a function that accepts a even-numbered list and faro shuffles the indices.

Example
Faro shuffling the list: ['ace', 'two', 'three', 'four', 'five', 'six']
will give ['ace', 'four', 'two', 'five', 'three', 'six']
*/

vector<string> faroShuffle(vector<string> deck){
    int middle = deck.size()/2;
    vector<string> faroShuffled;
    for(int i=0;i<middle;i++){
        faroShuffled.push_back(deck[i]);
        faroShuffled.push_back(deck[middle+i]);
    }
    return faroShuffled;
}

// main function
int main(){
    vector<string> fs = faroShuffle({"ace", "two", "three", "four", "five", "six"});
    for(auto s : fs)
        cout << s << "\n";
    return 0;
}