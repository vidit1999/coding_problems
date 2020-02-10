#include <iostream>
using namespace std;

/*
Your goal is to create a function that removes the first and last letters of a string.
Strings with two characters or less are considered invalid.
You can choose to have your function return null or simply ignore. 
*/

string removeFirstLast(string s){
	if(s.length() > 2)
		return s.substr(1,s.length()-2);
	return "";
}

// main function
int main(){
	string s = "th";
	cout << removeFirstLast(s) << "\n";
	return 0;
}