#include <bits/stdc++.h>
using namespace std;

/*
Step 1: Create a function called encode() to replace all the lowercase vowels in
a given string with numbers according to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about
uppercase letters for this challenge.

Step 2: Now create a function called decode() to turn the numbers back into vowels
according to the same pattern shown above. For the sake of simplicity,
you can assume that any numbers passed into the function will correspond to vowels.

For example, decode("h3 th2r2") would return "hi there".

Tests
decode('h2ll4'), 'hello')
encode('This is an encoding test.')
encode('How are you today?')
encode('This is an encoding test.')
*/

unordered_map<char, char> vowelToIndex = {
	{'a', '1'},
	{'e', '2'},
	{'i', '3'},
	{'o', '4'},
	{'u', '5'}
}, indexToVowel = {
	{'1', 'a'},
	{'2', 'e'},
	{'3', 'i'},
	{'4', 'o'},
	{'5', 'u'}
};

string encode(string text){
	string encoded = "";
	
	for(char c : text)
		encoded += ((vowelToIndex.find(c) != vowelToIndex.end())? vowelToIndex[c] : c);
	
	return encoded;
}

string decode(string text){
	string decoded = "";
	
	for(char c : text)
		decoded += ((indexToVowel.find(c) != indexToVowel.end())? indexToVowel[c] : c);
	
	return decoded;
}

// main function
int main(){
	cout << decode("h3 th2r2") << "\n";
	cout << decode("h2ll4") << "\n";
	cout << encode("hello") << "\n";
	cout << encode("This is an encoding test.") << "\n";
	cout << encode("How are you today?") << "\n";
	cout << encode("This is an encoding test.") << "\n";
	return 0;
}