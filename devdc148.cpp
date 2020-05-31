#include <bits/stdc++.h>
using namespace std;

/*
Setup
Trolls are invading the comment section!

To deal with the threat, write a function that takes a string and returns a
new string with all vowels removed (y not included).

Example
"This website is for losers LOL!" => "Ths wbst s fr lsrs LL"

Tests
"No newbies allowed, go to #beginners" =>
"LULZ TROLLED" =>
*/

string removeVowel(string s){
	string ans = "";
	unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
	
	for(char c : s)
		if(vowels.find(tolower(c)) == vowels.end())
			ans += c;
	
	return ans;
}

// main function
int main(){
	cout << removeVowel("This website is for losers LOL!") << "\n";
	cout << removeVowel("No newbies allowed, go to #beginners") << "\n";
	cout << removeVowel("LULZ TROLLED") << "\n";
	return 0;
}