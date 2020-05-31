#include <bits/stdc++.h>
using namespace std;

/*
We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers.
The input numbers are strings and the function must return a string.

Example:

add("123", "321"); -> "444"
add("11", "99"); -> "110"

Notes:

The input numbers are big.
The input is a string of only digits
The numbers are positives
*/

string add(string num1, string num2){
	if(num1.length() < num2.length())
		swap(num1, num2);
	
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	string ans = "";
	int n1 = num1.length(), n2 = num2.length(), carry = 0;
	
	for(int i=0;i<n2;i++){
		int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = sum/10;
		ans.push_back(sum%10 + '0');		
	}
	
	
	for(int i=n2;i<n1;i++){
		int sum = (num1[i] - '0') + carry;
		carry = sum/10;
		ans.push_back(sum%10 + '0');
	}
	
	if(carry > 0)
		ans.push_back(carry + '0');
	
	reverse(ans.begin(), ans.end());
	return ans;
}

// main function
int main(){
	cout << add("123", "12") << "\n";
	cout << add("123", "321") << "\n";
	cout << add("11", "99") << "\n";
	return 0;
}