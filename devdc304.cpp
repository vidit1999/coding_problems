#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
In this challenge, we will check if a string contains consecutive
letters as they appear in the English alphabet and if each letter occurs only once.

Rules are: (1) the letters are adjacent in the English alphabet,
and (2) each letter occurs only once.

For example:
solve("abc") = True, because it contains a,b,c
solve("abd") = False, because a, b, d are not consecutive/adjacent in the alphabet, and c is missing.
solve("dabc") = True, because it contains a, b, c, d
solve("abbc") = False, because b does not occur once.
solve("v") = True
All inputs will be lowercase letters.

Tests
solve("abc")
solve("zyx")
solve("azj")
*/

bool solve(string s){
	int char_count[ALPHABET_SIZE] = {0};

	for(char c : s){
		char_count[c-'a']++;
	}

	int i = 0, cons_one_count = 0;

	while(i < ALPHABET_SIZE){
		if(char_count[i++] == 0){
			continue;
		}
		else if(char_count[i++] > 1){
			return false;
		}
		else{ // if char_count[i] == 1
			cons_one_count++;
			while(i < ALPHABET_SIZE && char_count[i] == 1){
				i++;
			}
		}
	}

	return (cons_one_count <= 1);
}

// main function
int main(){
	cout << solve("abc") << "\n";
	cout << solve("abd") << "\n";
	cout << solve("dabc") << "\n";
	cout << solve("abbc") << "\n";
	cout << solve("v") << "\n";
	cout << solve("abc") << "\n";
	cout << solve("zyx") << "\n";
	cout << solve("azj") << "\n";
	
	return 0;
}