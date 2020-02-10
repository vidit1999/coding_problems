#include <bits/stdc++.h>
using namespace std;

/*

Primary :

The first part of this challenge is to create a method that can determine whether
a number is a cubic number or not. If the number has been determined to not be cubic,
the output should be either null or the string "Unlucky."
Cubic numbers are numbers with at most three digits, such that
the sum of the cubes of their digits is the number itself.

For example: 153 is a cubic number, because 1^3 + 5^3 + 3^3 = 153.

Secondary :

If you are looking for more of a challenge, you can attempt to create a
function that can find cubic numbers in a string. In the output,
the numbers should be returned in the order in which they are encountered in the input string.

Example:
s = “aqdf& 0 1 xyz 153 777.777" should return “0 1 153 154”
s = “QK29 45[&erui” should return “Unlucky” or null.

Note :

In a string where three digits or more follow each other, the function should examine the numbers in sets
of three digits starting from the left. In string “001234”, the function should see 001, then 234, evaluate each,
then return any cubic numbers it found (e.g. “24172410” becomes “241”, “724”, and “10”). 

*/

// returns a vector of numbers if number have more than 3 digits
vector<int> splitNum(string num){
	int startPos = 0;
	vector<int> v;
	while(startPos < num.length()){
		v.push_back(stoi(num.substr(startPos,3)));
		startPos += 3;
	}
	return v;
}


// function to check if a string is integer number or not
bool isInteger(string num){
	for(int i=0;i<num.length();i++){
		if(num[i] < 48 || num[i] > 57)
			return false;
	}
	return true;
}

// function to split a string delim is space
vector<string> splitedString(string s){
	vector<string> v;
	string token;
	for(int i=0;i<s.length(); i++){
		if(s[i] != ' ')
			token += s[i];
		else{
			if(!token.empty()){
				v.push_back(token);
				token = "";
			}
		}
	}
	if(!token.empty()){
		v.push_back(token);
		token = "";
	}
	return v;
}

// primary task
// numbers with 3 or less digits
bool isCubic(int num){
	if(num >= 1000)
		return false;
	int tempNum = num;
	int cubeSum = 0;
	while(tempNum != 0){
		int digit = tempNum % 10;
		cubeSum += digit*digit*digit;
		tempNum /= 10;
	}
	if(cubeSum == num)
		return true;
	return false;
}

// second task
string cubicNumbers(string s){
	vector<string> v = splitedString(s);
	string res = "";
	for(string sp : v){
		if(isInteger(sp)){
			vector<int> stNum = splitNum(sp);
			bool cubic = true;
			for(int i : stNum){
				if(!isCubic(i)){
					cubic = false;
					break;
				}
			}
			if(cubic){
				res += (sp + " ");
			}
		}
	}
	return res;
}

// main function
int main(){
	string num = "aqdf& 0 1 xyz 153";
	// if(isCubic(num))
		// cout << "Yes\n";
	// else
		// cout << "Null\n";
	
	cout << cubicNumbers(num) << "\n";
	
	return 0;
}