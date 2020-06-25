#include <bits/stdc++.h>
using namespace std;

/*
Convert a given integer to binary. Return 1 when ANY odd bit of x equals 1; 0 otherwise.

Examples
any_odd(2) will return 1 because at least one odd bit is 1 (0010).
any_odd(170) will return 1 because all of the odd bits are 1 (10101010).

Tests
any_odd(5)
any_odd(7)
any_odd(10)
*/

int any_odd(unsigned int number){
	return (number & 0xAAAAAAAA) != 0; // 0xAAAAAAAA has all its odd bits set, so if result is not 0 then number has at least one odd set bit
}

// main function
int main(){
	cout << any_odd(2) << "\n"; // output -> 1
	cout << any_odd(170) << "\n"; // output -> 1
	cout << any_odd(5) << "\n"; // output -> 0
	cout << any_odd(7) << "\n"; // output -> 1
	cout << any_odd(10) << "\n"; // output -> 1
	cout << any_odd(0) << "\n"; // output -> 0
	return 0;
}