#include <bits/stdc++.h>
using namespace std;

/*
Story

The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

But some of the rats are deaf and are going the wrong way!

How many deaf rats are there?

Legend

P = The Pied Piper
O~ = Rat going left
~O = Rat going right
Example

ex1 ~O~O~O~O P has 0 deaf rats
ex2 P O~ O~ ~O O~ has 1 deaf rat
ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
*/

int countDeafRats(string s){
	// position and direction of a rat
	// direction is true for left and false for right
	unordered_map<int, bool> ratPosDirec;
	int piedPosition, deafCount = 0;
	
	for(int i=0;i<s.length();i++){
		if(s[i] == '~'){
			ratPosDirec[i+1] = false;
			i++;
		}
		else if(s[i] == 'O'){
			ratPosDirec[i] = true;
			i++;
		}
		else if(s[i] == 'P')
			piedPosition = i;
	}
	
	for(auto it : ratPosDirec){
		if(
			// piper is in the left side but rat is heading towards right direction
			((it.first > piedPosition) && !it.second) ||
			// piper is in the right side but rat is heading towards left direction
			((it.first < piedPosition) && it.second)
		){
			deafCount++;
		}
	}
	
	return deafCount;
}

// main function
int main(){
	cout << countDeafRats("~O~O~O~O P") << "\n";
	cout << countDeafRats("P O~ O~ ~O O~") << "\n";
	cout << countDeafRats("~O~O~O~OP~O~OO~") << "\n";
	return 0;
}