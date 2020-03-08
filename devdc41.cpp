#include <bits/stdc++.h>
using namespace std;

/*
Greed is a dice game played with five six-sided dice.
Using an array containing five six-sided dice values,
write a function that will score a throw according to the following rules:

Three 1's => 1000 points
Three 6's => 600 points
Three 5's => 500 points
Three 4's => 400 points
Three 3's => 300 points
Three 2's => 200 points
One 1 => 100 points
One 5 => 50 point

A single die can only be counted once in each roll.
For example, a "5" can only count as part of a triplet
(contributing to the 500 points) or alone (as 50 points), but not both in the same roll.

Example Scoring
5 1 3 4 1 => 50 + 2 * 100 = 250
1 1 1 3 1 => 1000 + 100 = 1100
2 4 4 5 4 => 400 + 50 = 450

You can try to fill the array with random values.
If you have extra time, you can also try to keep track of the player's score over several throws.
*/

int totalScore(vector<int> scoreCard){
    unordered_map<int, int> scoreMap;
    for(int i : scoreCard)
        scoreMap[i]++;
    int points = 0;
    vector<int> threePointers = {1,2,3,4,5,6};
    for(int i : threePointers){
        while(scoreMap[i] >= 3){
            if(i != 1)
                points += 100*i;
            else
                points += 1000;
            scoreMap[i] -= 3;
        }
    }
    while(scoreMap[1] > 0){
        points += 100;
        scoreMap[1]--;
    }
    while(scoreMap[5] > 0){
        points += 50;
        scoreMap[5]--;
    }
    return points;
}

// main function
int main(){
    cout << totalScore({5, 1, 3, 4, 1}) << "\n";
    cout << totalScore({1, 1, 1, 3, 1}) << "\n";
    cout << totalScore({2, 4, 4, 5, 4}) << "\n";
    return 0;
}