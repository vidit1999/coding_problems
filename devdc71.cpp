#include <bits/stdc++.h>
using namespace std;

/*
You're saying goodbye to your friend when they say to you,
"See you next happy year!" You smile and wave, saying you'll see them then.
But wait, when's the next happy year anyway?

Given a year, write a function that will return the closest year you'll see your friend,
the next year with all unique digits.

Years will always be represented as positive integers.
It is not necessary for the year passed through the function to be a Happy one.

Examples:
nextHappyYear(7712) ==> 7801
nextHappyYear(1001) ==> 1023
nextHappyYear(2018) ==> 2019
*/

int nextHappyYear(int year){
	string year_string = to_string(++year);
	unordered_set<char> year_digits(year_string.begin(), year_string.end());
	if(year_digits.size() == year_string.length())
		return year;
	return nextHappyYear(year);
}

// main function
int main(){
	cout << nextHappyYear(7712) << "\n";
	cout << nextHappyYear(1001) << "\n";
	cout << nextHappyYear(2018) << "\n";
	return 0;
}