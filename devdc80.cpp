#include <bits/stdc++.h>
using namespace std;

/*
The vowel substrings in the word codewarriors are o,e,a,io.
The longest of these has a length of 2.
Given a lowercase string that has alphabetic characters only and no spaces,
return the length of the longest vowel substring. Vowels are any of aeiou.
*/

int longestVowelString(string s){
	int max_len = 0, temp_len = 0;
	for(char c : s){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			temp_len++;
		else{
			max_len = max(max_len, temp_len);
			temp_len = 0;
		}
	}
	
	return max(max_len, temp_len);
}

// main function
int main(){
	cout << longestVowelString("codewarriors") << "\n";
	return 0;
}