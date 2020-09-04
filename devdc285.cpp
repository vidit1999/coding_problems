#include <bits/stdc++.h>
using namespace std;

/*
Word on the street is that you claim to be a safe-cracking jewel thief.
But are you?

Let's test your safe-cracking abilities. To prove you are a real thief,
you need to crack the combination of the safe, then open it and tell me
the value of the jewels inside!

The safe object has two methods:

unlock(combination) returns a string.
click means the first part of the combination is correct,
click click for the first two parts,
click click click means all three are correct.

open() returns an integer containing the value of the safe's contents.

The safe combination format is made up of 3 dial spins:

Spin the dial left L or right R
Numbers on the dial 00 - 99
Each part of the combination is separated by -
*/

string unlock(vector<int>& actual_key, vector<int> key){
	string response = "";

	if((key.size() != actual_key.size()) || key.size() != 3)
		return response;

	if(key[0] == actual_key[0]){
		response += "click";
		if(key[1] == actual_key[1]){
			response += "click";
			if(key[2] == actual_key[2]){
				response += "click";
			}
		}
	}

	return response;
}

string open_safe(vector<int>& actual_key){
	vector<int> key(3, 100);
	string check_string = "";

	for(int part=0; part<3; part++){
		check_string += "click";
		for(int i=0; i<100; i++){
			key[part] = i;
			if(unlock(actual_key, key) == check_string)
				break;
		}
	}

	// print the secret key
	for(int i : key){
		cout << i << " ";
	}
	cout << "\n";

	return to_string(rand());
}

void testFunc(vector<vector<int>> actual_keys){
	for(auto actual_key : actual_keys){
		cout << open_safe(actual_key) << "\n";
	}
}

// main function
int main(){
	srand(time(0));
	
	testFunc({
		{27, 89, 56},
		{45, 12, 78},
		{19, 34, 10},
	});
	return 0;
}