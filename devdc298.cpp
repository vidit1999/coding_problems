#include <bits/stdc++.h>
using namespace std;

/*
Given a string of words, return the length of the shortest word in the string.

Examples
find_short("bitcoin take over the world maybe who knows perhaps"), 3)
find_short("turns out random test cases are easier than writing out basic ones"), 3)

Tests
find_short("let us talk about javascript")
find_short("i want to travel the world writing code one day")
find_short("Lets all go on holiday somewhere very cold")
*/

int find_short(string s){
	string temp = "";
	int min_len = INT_MAX;

	for(char c : s){
		if(c == ' '){
			if(!temp.empty()){
				min_len = min(min_len, int(temp.length()));
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}

	if(!temp.empty()){
		min_len = min(min_len, int(temp.length()));
	}

	return (min_len == INT_MAX)? 0 : min_len;
}

// main function
int main(){
	cout << find_short("bitcoin take over the world maybe who knows perhaps") << "\n";
	cout << find_short("turns out random test cases are easier than writing out basic ones") << "\n";
	cout << find_short("let us talk about javascript") << "\n";
	cout << find_short("i want to travel the world writing code one day") << "\n";
	cout << find_short("Lets all go on holiday somewhere very cold") << "\n";
	return 0;
}