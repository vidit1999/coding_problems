#include <bits/stdc++.h>
using namespace std;

/*
If you're faced with an input box, like this:
									     +--------------+
Enter the price of the item, in dollars: |              |
										 +--------------+

Do you put the $ sign in, or not? Inevitably, some people will type a
$ sign and others will leave it out. The instructions could be made
clearer - but that won't help those people who never read instructions anyway.

A better solution is to write code that can handle the input whether it includes a $ sign or not.

So, write a simple function that converts a string representing a
number into the number itself. Your function should be able to handle negatives!

Examples:

money_value("12.34") => 12.34
money_value("-0.89") => -0.89
money_value(" .11") => 0.11
money_value("007") => 7

Tests:
money_value("-$ 0.1")
money_value("12.34")
money_value("$-2.3456")
money_value("$.2")
*/

float money_value(string s){
    int sign = 1;
    string number;

    for(char c : s){
        if((c >= '0' && c <= '9') || c == '-' || c == '.'){
            if(c == '-') sign = -1;
            else number += c;
        }
    }

    return sign * stof(number);
}

// main function
int main(){
    cout << money_value("12.34") << "\n";
    cout << money_value("-0.89") << "\n";
    cout << money_value(" .11") << "\n";
    cout << money_value("007") << "\n";
    cout << money_value("-$ 0.1") << "\n";
    cout << money_value("12.34") << "\n";
    cout << money_value("$-2.3456") << "\n";
    cout << money_value("$.2") << "\n";
	return 0;
}