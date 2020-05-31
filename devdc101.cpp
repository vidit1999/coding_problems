#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will generate all possible combinations of grammatically correct parentheses.
The function should be able to work with n pairs of parentheses.

Given n = 3, an example solution set would be:

[
  "((()))",
  "(())()",
  "()(())",
  "()()()",
  "(()())"
]
*/


bool isValid(string parentheses){
	int countBrackets = 0;
	for(char c : parentheses){
		if(c == ')'){
			if(countBrackets == 0)
				return false;
			countBrackets--;
		}
		else
			countBrackets++;
	}
	return countBrackets==0;
}

vector<string> parenthesesPermutations(int n){
	if(n <= 0)
		return {};
	string base_string = "";
	for(int i=0;i<n;i++)
		base_string = "(" + base_string + ")";
	
	vector<string> ans;
	do{
		if(isValid(base_string))
			ans.push_back(base_string);
	}while(next_permutation(base_string.begin(), base_string.end()));
	
	return ans;
}

// main function
int main(){
	for(string s : parenthesesPermutations(3))
		cout << s << "\n";
	return 0;
}