#include <bits/stdc++.h>
using namespace std;

/*
You are creating a board game, similar to a mix between Fire Emblem and Chess.
The game features four unique pieces: Swordsman, Cavalry, Archer, and Pikeman.
Each piece has its own advantages and weaknesses in combat against other pieces.

You must write a function fightResolve that takes the attacking and defending
pieces as input parameters and returns the winning piece.

The outcome of the fight between two pieces depends on which piece attacks,
the type of the attacking piece and the type of the defending piece.

Archers > Swordsmen > Pikemen > Cavalry > Archers

Archers always win against swordsmen, swordsmen always win against pikemen,
pikemen always win against cavalry and cavalry always win against archers.

If a matchup occurs that was not previously mentioned
(for example Archers vs Pikemen) the attacker will always win. 
*/

string mixGame(string attacker, string defender){
	
	// store combinations of attacker and defender with winners of known fights
	map<pair<string, string>, string> knownResults;
	knownResults[make_pair("Archer","Swordsman")] = "Archer";
	knownResults[make_pair("Swordsman","Pikemen")] = "Swordsman";
	knownResults[make_pair("Pikemen","Cavalry")] = "Pikemen";
	knownResults[make_pair("Cavalry","Archer")] = "Cavalry";

	// if Archer fights with Swordsman then Archer will win
	// whether he fights as a defender or attacker does not matter
	// so check both cases
	if(knownResults.find(make_pair(attacker,defender)) != knownResults.end())
		return knownResults[make_pair(attacker,defender)];
	if(knownResults.find(make_pair(defender,attacker)) != knownResults.end())
		return knownResults[make_pair(defender,attacker)];
	
	// if combination is not known then attacker will win
	return attacker;
}

// main function
int main(){
	cout << mixGame("Archer", "Swordsman") << "\n";
	cout << mixGame("Archer", "Cavalry") << "\n";
	cout << mixGame("Archer", "Pikeman") << "\n";
	return 0;
}