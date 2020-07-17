#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, you will be given a string that may have mixed uppercase
and lowercase letters and your task is to convert that string to either
lowercase only or uppercase only based on:

making as few changes as possible
if the string contains equal number of uppercase and lowercase letters,
convert the string to lowercase.

For example:
solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.

Tests:
solve("code")
solve("CODe")
solve("COde")
solve("Code")
*/

string solve(string s){
	int lower_count = 0;
	string new_string;

	for(char c : s)
		if(islower(c))
			lower_count++;

	if(2*lower_count >= s.length()){
		for(char c : s) new_string += tolower(c);
	}
	else{
		for(char c : s) new_string += toupper(c);
	}
	
	return new_string;
}

// main function
int main(){
	cout << solve("code") << "\n";
	cout << solve("CODe") << "\n";
	cout << solve("COde") << "\n";
	cout << solve("Code") << "\n";
	return 0;
}