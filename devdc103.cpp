#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will take a string and determine if it is an acceptable sequence.
The string will be composed of + and = symbols with several characters between them.
For the string to be acceptable, each character must be surrounded by + symbols.

Examples:
(++d+===+c++==a) => false, because a is not surrounded by +.
(+d+e+===+q+=) => true, because all characters are surrounded by +.

Test cases:
"f++d+"
"++q++qq=z"
"==++z+=+q+"
*/

bool acceptableSeq(string seq){
	for(int i=0;i<seq.length();i++)
		if(seq[i] != '+' && seq[i] != '=')
			if(i == 0 || i == seq.length()-1 || seq[i-1] != '+' || seq[i+1] != '+')
				return false;
	return true;
}

void testFunc(vector<string> v){
	for(string s : v)
		if(acceptableSeq(s))
			cout << "Yes\n";
		else
			cout << "No\n";
}

// main function
int main(){	
	testFunc({
		"++d+===+c++==a",
		"+d+e+===+q+=",
		"f++d+",
		"++q++qq=z",
		"==++z+=+q+"
	});
	return 0;
}