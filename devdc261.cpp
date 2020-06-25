#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, you'll be given an array of strings with
N elements and each element has N length.

First, sort the given array alphabetically.
Your output will consist of letters obtained diagonally
(from top left to bottom right). Collect the new string,
then change the order and obtain a new string.
Repeat this process until you have as many strings as was originally given in the array.

Example:

1234                       Abcd                           
aBcd                       kAta                           
kaTa                       qwEr                           
qweR -> 1234 => "1btr"     1234 -> abcd => "aae4"         

Kata                       Qwer
qWer                       1234
1234                       abCd
abcD -> kata => "kw3d"     katA -> qwer => "q2ca"

Output : {"aae4","kw3d","1btr","q2ca"} (by input order)

Tests:
string[] { "1a8er", "B36jh", "AiYe3", "B1t0a", "g47uj" };
string[] { "ab", "12" };
*/

bool validateInputs(vector<string> arr){
	for(string s : arr)
		if(s.length() != arr.size())
			return false;
	return true;
}

vector<string> diagonalize(vector<string> arr){
	if(!validateInputs(arr))
		return {};

	sort(arr.begin(), arr.end());
	int n = arr.size();
	
	vector<string> ans;

	for(int i=0; i<n; i++){
		string s = "";
		for(int j=0; j<n ; j++){
			s += tolower(arr[(i+j)%n][j]);
		}
		ans.push_back(s);
	}

	return ans;
}

void testFunc(vector<vector<string>> arr){
	for(auto v : arr){
		for(string s : diagonalize(v))
			cout << s << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{"1234", "aBcd", "kaTa", "qweR"},
		{"1a8er", "B36jh", "AiYe3", "B1t0a", "g47uj"},
		{"ab", "12" }
	});
	return 0;
}