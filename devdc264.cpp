#include <bits/stdc++.h>
using namespace std;

/*
Digital root is the recursive sum of all the digits in a number. Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. This is only applicable to the natural numbers.

Examples
16  -->  1 + 6 = 7
942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11 --> 1 + 1 = 2

Tests
digital_root(456)
digital_root(16)
*/

int digital_root(int number){
	if(number < 10)
		return number;

	int digit_sum = 0;
	while(number){
		digit_sum += number%10;
		number /= 10;
	}

	return digital_root(digit_sum);
}

// main function
int main(){
	cout << digital_root(16) << "\n";
	cout << digital_root(456) << "\n";
	cout << digital_root(942) << "\n";
	cout << digital_root(132189) << "\n";
	cout << digital_root(493193) << "\n";
	return 0;
}