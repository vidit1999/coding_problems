#include <bits/stdc++.h>
using namespace std;

/*
Complete the function that accepts a string parameter,
and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"

"double spaces" ==> "elbuod secaps"

Tests
reverseWords("The quick brown fox jumps over the lazy dog.")
reverseWords("double spaced words")
*/

string reverseWords(string s){
	reverse(s.begin(), s.end());
	vector<string> reverseArray;

	string temp = "";
	for(char c : s){
		if(c == ' ' && !temp.empty()){
			reverseArray.push_back(temp);
			temp = "";
		}
		else
			temp += c;
	}
	if(!temp.empty()){
		reverseArray.push_back(temp);
		temp = "";
	}

	for(int i=0;i<reverseArray.size();i++){
		temp = reverseArray[i] + temp;
		if(i != reverseArray.size()-1)
			temp = ' ' + temp;
	}

	return temp;
}

void testFunc(vector<string> arr){
	for(string s : arr){
		cout << reverseWords(s) << "\n";
	}
}

// main function
int main(){
	testFunc({
		"double spaces",
		"This is an example!",
		"The quick brown fox jumps over the lazy dog.",
		"double spaced words"
	});
	return 0;
}