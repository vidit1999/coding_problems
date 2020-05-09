#include <bits/stdc++.h>
using namespace std;

/*
If you are faced with an input box like this:

											+--------------+
Enter the price of the item, in dollars: 	|              |
											+--------------+
Do you put the dollar sign in or not? Inevitably,
some people will type a dollar sign while others will leave it out.
The instructions could be made clearer - but that won't stop those that don't read them.

Write a function that converts a string representing a number into the number itself.
Consider negative numbers and any extraneous space characters that the user might put in.
If the given string does not represent a number, return 0.0.

Sample Cases:
money_value("12.34")
money_value(" $5.67")
money_value("-$ 0.1")
money_value("$-2.3456")
money_value("007")
money_value(" $ 89")
money_value("   .11")
money_value("$.2")
money_value("-.34")
money_value("$$$")
*/

float money_value(string number){
	string cleaned = "";
	int dotCount = 0, negCount = 0, digitCount = 0;
	for(char c : number){
		if(c == '-' || c == '.' || (c >= '0' && c <= '9'))
			cleaned += c;
		else if(c != '$' && c != ' ')
			return 0;
			
		if(c == '.')
			dotCount++;
		else if(c == '-')
			negCount++;
		else if(c >= '0' && c <= '9')
			digitCount++;
	}
	
	if(negCount > 1 || dotCount > 1 || digitCount < 1 || (negCount > 0 && cleaned[0] != '-'))
		return 0;
	
	int sign = (negCount > 0)? -1 : 1;
	return sign * stof(cleaned.substr((negCount > 0), cleaned.length()-(negCount > 0)));
}

// main function
int main(){
	cout << money_value("12.34") << "\n";
	cout << money_value(" $5.67") << "\n";
	cout << money_value("-$ 0.1") << "\n";
	cout << money_value("$-2.3456") << "\n";
	cout << money_value("007") << "\n";
	cout << money_value(" $ 89") << "\n";
	cout << money_value("   .11") << "\n";
	cout << money_value("$.2") << "\n";
	cout << money_value("-.34") << "\n";
	cout << money_value("$$$") << "\n";
	return 0;
}