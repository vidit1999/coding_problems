#include <bits/stdc++.h>
using namespace std;

/*
Given a string of numbers confirm whether the total of all the individual
even numbers are greater than the total of all the individual odd numbers.
Always a string of numbers will be given.

If the sum of even numbers is greater than the odd numbers return:
Even is greater than Odd

If the sum of odd numbers is greater than the sum of even numbers return:
Odd is greater than Even

If the total of both even and odd numbers are identical return:
Even and Odd are the same
*/

string oddVsEven(string number){
	int evenSum = 0, oddSum = 0;
	
	for(char c : number){
		if(c%2 == 0)
			evenSum += c-'0';
		else
			oddSum += c-'0';
	}
	
	if(evenSum > oddSum)
		return "Even is greater than Odd";
	else if(oddSum > evenSum)
		return "Odd is greater than Even";
	
	return "Even and Odd are the same";
}

// main function
int main(){
	cout << oddVsEven("221") << "\n";
	cout << oddVsEven("237") << "\n";
	cout << oddVsEven("112") << "\n";
	return 0;
}