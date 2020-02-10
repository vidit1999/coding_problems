#include <iostream>
using namespace std;

/*
Write a function that returns the number (count) of vowels in a given string.
Letters considered as vowels are: a, i, e, o, and u. The function should be able to take all
types of characters as input, including lower case letters, upper case letters, symbols, and numbers.

In this challenge, you should be able to efficiently ignore spaces and symbols and discern
between capital and lowercase letters.
*/

bool isVowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		return true;
	return false;
}

int countVowel(string s){
	int count = 0;
	for(int i=0;i<s.length();i++){
		if(isVowel(s[i]))
			count++;
	}
	return count;
}

// main function
int main(){
	string s = "this is a test";
	cout << countVowel(s) << "\n";
	return 0;
}