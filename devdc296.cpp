#include <bits/stdc++.h>
using namespace std;

/*
The first century spans from the year 1 up to and including the year 100,
The second - from the year 101 up to and including the year 200, etc.
Return the century of the input year.

Examples
"1999" --> "20th"
"2011" --> "21st"
"2154" --> "22nd"
"2259" --> "23rd"
"1124" --> "12th"
"2000" --> "21st"
"20000" --> "210th"

Tests
8120
30200
1601
2020
3030
1900
1776
*/

string getPrefixCentury(int century){
	if(century%100 >= 11 && century%100 <= 13){
		return "th";
	}
	
	switch(century%10){
		case 1 : return "st";
		case 2 : return "nd";
		case 3 : return "rd";
		default : return "th";
	}
}


string getCentury(int year){
	int century = year/100 + 1;
	return to_string(century) + getPrefixCentury(century);
}

void testFunc(vector<int> v){
	for(int year : v){
		cout << year << " --> " << getCentury(year) << "\n";
	}
}

// main function
int main(){
	vector<int> v = {
		8120,
		30200,
		1601,
		2020,
		3030,
		1900,
		1776,
		1999,
		2011,
		2154,
		2259,
		1124,
		2000,
		20000,
	};
	
	testFunc(v);
	return 0;
}