#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that accepts an array of 10 integers.
Have the function return those numbers as a String in the form of a phone number.
Please use the following format for the phone number: (XXX) XXX-XXXX.
Integers in the array will be no larger than 9.

Example
createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) // should return (123) 456-7890

Tests
createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])
createPhoneNumber([1, 1, 1, 1, 1, 1, 1, 1, 1, 1])
createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])
*/

// create phone number
string createPhoneNumber(vector<int> arr){
    string s = "";
	for(int i=0;i<10;i++){
		if(i==0)
			s += '(';
		if(i==3)
			s += ") ";
		if(i==6)
			s += '-';
		s += to_string(arr[i]);
	}
	return s;
}

// function for testing
void testFunction(vector<int> arr){
    cout << createPhoneNumber(arr) << "\n";
}

// main function
int main(){
    testFunction({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
    testFunction({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    return 0;
}