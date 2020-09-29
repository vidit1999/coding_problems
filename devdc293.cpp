#include <bits/stdc++.h>
using namespace std;

/*
You'll be given a string with numbers as input.
The first two numbers are the operands,
while the last three are the result of the operation.

Available operations include:

addition
subtraction
multiplication
division
Example
For string: 9 4 5 20 25

Your function must return: subtraction, multiplication, addition

Because:
9 - 4 = 5         subtraction
4 * 5 = 20        multiplication
5 + 20 = 25       addition
*/

vector<string> splitString(string s){
	vector<string> ans;

	string temp = "";

	for(char c : s){
		if(c == ' '){
			if(!temp.empty()){
				ans.push_back(temp);
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}

	if(!temp.empty()){
		ans.push_back(temp);
	}

	return ans;
}

string joinString(vector<string> v){
	int n = v.size();
	string ans = "";

	for(int i=0; i<n-1; i++){
		ans += (v[i] + ", ");
	}

	ans += v[n-1];

	return ans;
}

string getOperation(string num1, string num2, string res){
	int n1 = stoi(num1), n2 = stoi(num2), r = stoi(res);

    if(r == n1+n2) return "addition";
    else if(r == n1-n2) return "subtraction";
    else if(r == n1*n2) return "multiplication";
    else if(r == n1/n2) return "division";
    
	return "noop";
}

string operationNames(string s){
	auto splited = splitString(s);
	vector<string> ops;

	for(int i=0; i<splited.size()-2; i++){
		string num1 = splited[i], num2 = splited[i+1], res = splited[i+2];
		ops.push_back(getOperation(num1, num2, res));
	}

	return joinString(ops);
}

// main function
int main(){
	string s = "9 4 5 20 25";
	
    cout << operationNames(s) << "\n";
	
	return 0;
}