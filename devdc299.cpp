#include <bits/stdc++.h>
using namespace std;

/*
A grille cipher was a technique for encrypting plaintext by writing
it onto a sheet of paper through a pierced sheet. The earliest known
use is from the mathematician Girolamo Cardano in 1550.
His proposal was for a rectangular stencil allowing single letters,
syllables, or words to be written, then later read.
The written fragments of the plaintext could be further
disguised by filling the gaps between the fragments with benign words or letters.

Wikipedia: https://en.wikipedia.org/wiki/Grille_(cryptography)

Write a function that accepts two inputs: message and code.
Code is a non-negative integer and should be converted to binary.
Overlay the code converted to binary and the message to reveal the result.

Example
Grille("abcdef", 5)  => "df"

* convert 5 to binary:
 000101

* overlay message and code:
message : abcdef
code    : 000101
----------------
result  : df
Tests
Grille("0abc", 2)

Grille("abcde", 32)

Grille("abcd", 1)
*/

string Grille(string s, int num){
	string ans = "";
	reverse(s.begin(), s.end());
	
	for(char c : s){
		if(num == 0)
			break;
		if(num%2 == 1){
			ans = c + ans;
		}
		num >>= 1;
	}

	return ans;
}

// main function
int main(){
	cout << Grille("abcdef", 5) << "\n";
	cout << Grille("0abc", 2) << "\n";
	cout << Grille("abcde", 32) << "\n";
	cout << Grille("abcd", 1) << "\n";
	return 0;
}