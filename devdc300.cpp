#include <bits/stdc++.h>
using namespace std;

/*
You are writing a password validator for a website. You want to discourage
users from using their username as part of their password, or vice-versa,
because it is insecure. Since its unreasonable to not allow them to have
any letters in common, you come up with this rule:

For any password and username pair, the length of the longest common substring
should be less than half the length of the shortest of the two.

In other words, you won't allow users to have half their password repeated
in their username, or half their username repeated in their password.

Write a function validate(username, password) which returns true
if your rule is followed, false otherwise.

Assume both the username and the password may contain uppercase
letters, lowercase letters, numbers, spaces, and the following
special/punctation characters: !@#$%^&*()_+{}:"<>?[];',.
The username and password will each be less than 100 characters.

Examples
validate("newyorkcity", "yankees101"), TRUE
validate("username", "usernamePW"), FALSE

Tests
validate("Paa2", "Paaaaaa222!!!")
validate("wordpass", "password")
validate("superman", "persuzod")
*/

bool validate(string username, string password){
	int m = username.length();
	int n = password.length();
	float threshold = float(min(m,n))/2.0;
	int lcs_length = 0;
	
	int lcs[m+1][n+1];

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 || j == 0)
				lcs[i][j] = 0;
			else if(username[i-1] == password[j-1]){
				lcs[i][j] = 1 + lcs[i-1][j-1];
				lcs_length = max(lcs_length, lcs[i][j]);
				if(lcs_length >= threshold)
					return false;
			}
			else{
				lcs[i][j] = 0;
			}
		}
	}

	return true;
}

// main function
int main(){
	cout << validate("newyorkcity", "yankees101") << "\n";
	cout << validate("username", "usernamePW") << "\n";
	cout << validate("Paa2", "Paaaaaa222!!!") << "\n";
	cout << validate("wordpass", "password") << "\n";
	cout << validate("superman", "persuzod") << "\n";
	return 0;
}