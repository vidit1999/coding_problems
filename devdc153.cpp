#include <bits/stdc++.h>
using namespace std;

/*
Your friend likes to go to the horse races and gamble on which horses will finish first, second,
and third place. Unfortunately, he doesn't know how many horses will be entering until he gets to the track.

Write a function that will take any number of horses as its only argument.
This function must return the total number of different combinations of winners
for the gold, silver, and bronze medals.

For example, if there are 15 horses, there are 2730 possible unique combinations of winners.
If the number of horses is 3 or less, return the input value. If the number of horses is not an integer,
return undefined.

Examples
horses(15), 2730, true)
horses(2.5), undefined, false)
*/

int horses(float number){
	return (int(number) == number)? ((number <= 3)? number : (number-2)*(number-1)*number) : -1;
}


// main function
int main(){
	cout << horses(15) << "\n";
	cout << horses(2.5) << "\n";
	cout << horses(12) << "\n";
	cout << horses(2) << "\n";
	cout << horses(11) << "\n";
	return 0;
}