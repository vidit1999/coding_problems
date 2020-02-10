#include <bits/stdc++.h>
using namespace std;

/*

Create a simple calculator that given a string of operators (+ - * and /)
and numbers separated by spaces returns the value of that expression

Example:
Calculator().evaluate("2 / 2 + 3 * 4 - 6") # => 7

Remember about the order of operations! Multiplications and divisions have a higher
priority and should be performed left-to-right.
Additions and subtractions have a lower priority and should also be performed left-to-right.

*/

// split string delim as space
// returns a vector
vector<string> splited(string s){
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

// chaeck if a string is operator or operand
bool isOperator(string s){
	if(s == "+" || s=="-" || s=="*" || s=="/")
		return true;
	return false;
}

// performs operations
string operation(string op1, string op2, string oprtn){
	if(oprtn == "*")
		return to_string(stoi(op1)*stoi(op2));
	else if(oprtn == "/")
		return to_string(stoi(op1)/stoi(op2));
	else if(oprtn == "+")
		return to_string(stoi(op1)+stoi(op2));
	else if(oprtn == "-")
		return to_string(stoi(op1)-stoi(op2));
}

int calculator(string s){
	vector<string> splitedString = splited(s);
	stack<string> operand; // stack to store the operands
	stack<string> opertr; // stack to store the operators
	for(string s : splitedString){
		if(!isOperator(s)){
			if(!opertr.empty() && (opertr.top() == "*" || opertr.top() == "/")){
				string op1 = operand.top();
				operand.pop();
				string oprtn = opertr.top();
				opertr.pop();
				operand.push(operation(op1,s,oprtn));
			}
			else
				operand.push(s);
		}
		else
			opertr.push(s);
	}
	
	while(!operand.empty() && !opertr.empty()){
		string op2 = operand.top();
		operand.pop();
		string op1 = operand.top();
		operand.pop();
		string oprtn = opertr.top();
		opertr.pop();
		operand.push(operation(op1,op2,oprtn));
	}
	
	int res = stoi(operand.top());
	operand.pop();
	return res;
}


// main function
int main(){
	string s = "2 * 2 * 3";
	cout << s << " =====> " << calculator(s);
	return 0;
}