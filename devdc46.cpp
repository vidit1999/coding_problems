#include <bits/stdc++.h>
using namespace std;

/*
Write a function which removes all question marks from a given string.
For example: hello?
would be : hello
*/

void removeQuestionMark(string& s){
	s.erase(remove_if(s.begin(),s.end(),[](char c){return c == '?';}), s.end());
}

// main function
int main(){
	string s = "h?e??ll??o????";
	cout << s << "\n";
	removeQuestionMark(s);
	cout << s << "\n";
	return 0;
}