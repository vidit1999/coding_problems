#include <bits/stdc++.h>
using namespace std;

/*
If　a = 1, b = 2, c = 3 ... z = 26

Then l + o + v + e = 54

and f + r + i + e + n + d + s + h + i + p = 108

So friendship is twice as strong as love :-)

Write a function to find the "strength" of each of these values.

Test cases:
wordsToMarks(attitude)
wordsToMarks(friends)
wordsToMarks(family)
wordsToMarks(selflessness)
wordsToMarks(knowledge)
*/

int wordsToMarks(string word){
	int strength = 0;
	
	for(char c : word)
		strength += tolower(c)-'a'+1;
	
	return strength;
}

// main function
int main(){
	cout << wordsToMarks("love") << "\n";
	cout << wordsToMarks("friendship") << "\n";
	cout << wordsToMarks("attitude") << "\n";
	cout << wordsToMarks("friends") << "\n";
	cout << wordsToMarks("family") << "\n";
	cout << wordsToMarks("selflessness") << "\n";
	cout << wordsToMarks("knowledge") << "\n";
	return 0;
}