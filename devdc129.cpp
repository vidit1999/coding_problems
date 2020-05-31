#include <bits/stdc++.h>
using namespace std;

/*
Pete and his mate Phil are out in the countryside shooting clay pigeons with a
shotgun - amazing fun. Some of the targets have something attached to create lots of
smoke when hit, guaranteed by the packaging to generate 'real excitement!'

They decide to have a competition. 3 rounds, 2 shots each. Winner is the one with the most hits.

For each round you will receive the following format:

[{P1:'XX', P2:'XO'}, true]

That is an array containing an object and a boolean. Pl represents Pete, P2 represents Phil.
X represents a hit and O represents a miss. If the boolean is true, any hit is worth 2.
If it is false, any hit is worth 1.

Find out who won. If it's Pete, return 'Pete Wins!'. If it is Phil, return 'Phil Wins!'.
If the scores are equal, return 'Draw!'.

Note that as there are three rounds, the actual input (x) will look something like this:

[[{P1:'XX', P2:'XO'}, true], [{P1:'OX', P2:'OO'}, false], [{P1:'XX', P2:'OX'}, true]]

Test Cases:

shoot([[{P1:'XX', P2:'XO'}, false], [{P1:'OX', P2:'XX'}, false], [{P1:'OO', P2:'XX'}, true]])

shoot([[{P1:'XX', P2:'XO'}, true], [{P1:'OX', P2:'OO'}, false], [{P1:'XX', P2:'OX'}, true]])
*/

int countScore(string shots, bool worth){
	int score = 0;
	for(char c : shots)
		score += (c == 'X')? (worth)? 2 : 1 : 0;
	return score;
}

string shoot(vector<pair<unordered_map<string, string>, bool>> competition){
	int peteScore = 0, philScore = 0;
	
	for(auto round : competition){
		bool worth = round.second;
		for(auto shot : round.first){
			if(shot.first == "P1")
				peteScore += countScore(shot.second, worth);
			else
				philScore += countScore(shot.second, worth);
		}
	}
	
	return (peteScore > philScore)? "Pete Wins!" : (peteScore == philScore)? "Draw!" : "Phil Wins!";
}

// main function
int main(){
	cout << shoot({
		{{{"P1","XX"}, {"P2","XO"}}, false},
		{{{"P1","OX"}, {"P2","XX"}}, false},
		{{{"P1","OO"}, {"P2","XX"}}, true}
	}) << "\n";
	
	cout << shoot({
		{{{"P1","XX"}, {"P2","XO"}}, true},
		{{{"P1","OX"}, {"P2","OO"}}, false},
		{{{"P1","XX"}, {"P2","OX"}}, true}
	}) << "\n";
	return 0;
}