#include <bits/stdc++.h>
using namespace std;

/*
Write simple .camelCase method (camel_case function in PHP, CamelCase in C# or camelCase in Java) for strings.
All words must have their first letter capitalized without spaces.

For instance:

camelcase("hello case") => HelloCase
camelcase("camel case word") => CamelCaseWord
*/

string camelCase(string s){
	string camel = "";
	bool capital = true;
	for(char c : s){
		if(c == ' '){
			capital = true;
			continue;
		}
		if(capital){
			camel += toupper(c);
			capital = false;
		}
		else
			camel += c;
	}
	return camel;
}

// main function
int main(){
	cout << camelCase("hello case")  << "\n";
	cout << camelCase("camel case word") << "\n";
	return 0;
}