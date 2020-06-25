#include <bits/stdc++.h>
using namespace std;

/*
The goal of this exercise is to convert a string to a new string
where each character in the new string is "(" if that character
appears only once in the original string, or ")" if that character
appears more than once in the original string.
Ignore capitalization when determining if a character is a duplicate.

Examples
"Success" => ")())())"
"(( @" => "))(("

Tests
"din"
"recede"
*/

string encodeDuplicate(string s){
	// stores the count of corresponding character (lower cased) in s
	unordered_map<char, int> charCount;
	
	for(char c : s) charCount[tolower(c)]++;
	
	string ans = "";
	
	for(char c : s) ans += (charCount[tolower(c)] > 1)? ')' : '(';
	
	return ans;
}

// main function
int main(){
	cout << encodeDuplicate("Success") << "\n";
	cout << encodeDuplicate("(( @") << "\n";
	cout << encodeDuplicate("din") << "\n";
	cout << encodeDuplicate("recede") << "\n";
	return 0;
}