#include <bits/stdc++.h>
using namespace std;

/*

Write a function that accepts an array of 10 integers (between 0 and 9),
that returns a string of those numbers in the form of a phone number.

createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) // => returns "(123) 456-7890"

The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses!

*/

string getPhoneNumber(int arr[], int n){
	string s = "";
	for(int i=0;i<n;i++){
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

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int n = 10;
	cout << getPhoneNumber(arr,n) << "\n";
	return 0;
}