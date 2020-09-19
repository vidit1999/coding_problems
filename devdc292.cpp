#include <bits/stdc++.h>
using namespace std;

/*
ISBN-10 identifiers are ten digits. The first nine digits are on the range 0 to 9.
The last digit can be either on the range 0 to 9 or the letter 'X' used to indicate a value of 10.

For an ISBN-10 to be valid, the sum of the digits multiplied by their position
has to equal zero modulo 11. For example, the ISBN-10: 1112223339 is valid because:
(((1*1)+(1*2)+(1*3)+(2*4)+(2*5)+(2*6)+(3*7)+(3*8)+(3*9)+(9*10)) % 11) == 0

Create the function validISBN10() to return true if and only if the input is a valid ISBN-10 Identifier.

Examples
validISBN10('1293000000'), true
validISBN10('048665088X'), true
validISBN10('1234512345'), false
validISBN10('1293') , false

Tests
validISBN10('1112223339')
validISBN10('X123456788')
validISBN10('1234512345')
*/

bool validISBN10(string isbn){
	// if length is not equal to 10 then return false
	if(isbn.length() != 10) return false;

	// if first 9 characters are not digits return false
	// if 10th character is not digit or 'X' return false
	for(int i=0; i<9; i++){
		if(isbn[i] < '0' || isbn[i] > '9')
			return false;
	}

	if((isbn[9] < '0' || isbn[9] > '9') && (isbn[9] != 'X'))
		return false;

	// count the total value
	int val = 0;

	for(int i=0; i<9; i++){
		val += (i+1)*(isbn[i]-'0');
	}

	if(isbn[9] == 'X'){
		val += 100;
	}
	else{
		val += 10*(isbn[9]-'0');
	}

	// return false if value is not divisible by 11
	return (val%11 == 0);
}

// main function
int main(){
	cout << validISBN10("1293000000") << "\n";
	cout << validISBN10("048665088X") << "\n";
	cout << validISBN10("1234512345") << "\n";
	cout << validISBN10("1293") << "\n";
	cout << validISBN10("1112223339") << "\n";
	cout << validISBN10("X123456788") << "\n";
	cout << validISBN10("1234512345") << "\n";
	return 0;
}