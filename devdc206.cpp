#include <bits/stdc++.h>
using namespace std;

/*
Assume "#" is like a backspace in string. This means that string "a#bc#d" would actually be "bd".
Implement a function that will process a string with "#" symbols and understand them as backspaces.

Examples
"abc#def##ghi###" ==> "abd"
"abc#d##c" ==> "ac"
"abc##d######" ==> ""
"#######" ==> ""
"" ==> ""

Tests
cleanString('abc#de##c')
cleanString('abc####dhh##c#')
cleanString('Thee# Empires# SS#tateBuildingg#')
*/

string cleanString(string s){
	string ans = ""; // the answer string
	int length = 0; // length of answer string
	for(char c : s){

		if(c == '#'){
			// if c == '#' and length > 0, then pop one character and decrement lenght
			if(length > 0){
				ans.pop_back();
				length--;
			}
		}
		// else add the character to string and increment length
		else{
			ans += c;
			length++;
		}
	}

	return ans;
}


// main function
int main(){
	cout << cleanString("Thee# Empires# SS#tateBuildingg#") << "\n";
	cout << cleanString("abc#d##c") << "\n";
	cout << cleanString("abc#def##ghi###") << "\n";
	cout << cleanString("abc##d######") << "\n";
	cout << cleanString("#######") << "\n";
	cout << cleanString("abc#de##c") << "\n";
	cout << cleanString("abc####dhh##c#") << "\n";
	cout << cleanString("abcdef") << "\n";
	return 0;
}