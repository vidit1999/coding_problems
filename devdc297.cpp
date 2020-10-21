#include <bits/stdc++.h>
using namespace std;

/*
Your task is to write a function loneliest() which accepts a string and will
return the character that has the most spaces to its right and left.

Examples
"a b  c"                        -->  ["b"]
"a bcs           d k"           -->  ["d"]
"    a b  sc     p     t   k"   -->  ["p"]
"a  b  c  de"                   -->  ["b", "c"]
"     a  b  c de        "       -->  ["b"]
"abc"                           -->  ["a", "b", "c"]

Tests
loneliest('abc d ef g h i j ')
loneliest('abc')
loneliest(' abc d z f gk s ')
*/

vector<char> loneliest(string s){
	unordered_map<int, vector<char>> space_char_map;
	
	int i=0, n = s.length();
	int left_spaces = 0, right_spaces = 0;
	
	while(i < n){
		
		// if there is any space before the first character
		// ignore it
		if(i == 0){
			while(i < n && s[i] == ' '){
				i++;
			}
			if(i == n) break;
		}
		
		char c = s[i++];
		
		while(i < n && s[i] == ' '){
			right_spaces++;
			i++;
		}
		
		// if there is any space after the last character
		// ignore it
		if(i == n){
			right_spaces = 0;
		}
		
		space_char_map[left_spaces + right_spaces].push_back(c);
		
		left_spaces = right_spaces;
		right_spaces = 0;
	}
	
	vector<char> ans;
	int max_len = INT_MIN;
	
	for(auto& it : space_char_map){
		if(it.first > max_len){
			max_len = it.first;
			ans = it.second;
		}
	}
	
	return ans;
}

void testFunc(vector<string> v){
	for(auto s : v){
		for(char c : loneliest(s)){
			cout << c << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		"a b  c",
		"a bcs           d k",
		"    a b  sc     p     t   k",
		"a  b  c  de",
		"     a  b  c de        ",
		"abc",
		"abc d ef g h i j ",
		"abc",
		" abc d z f gk s ",
	});
	return 0;
}