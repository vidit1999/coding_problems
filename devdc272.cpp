#include <bits/stdc++.h>
using namespace std;

/*
In a factory, a printer prints labels for boxes. For one kind of box,
the printer has to use colors which, for the sake of simplicity,
are named with letters from a to m.

The colors used by the printer are recorded in a control string.
For example a "good" control string would be aaabbbbhaijjjm meaning
that the printer used three times color a, four times color b,
one time color h then one time color a...

Sometimes there are problems: lack of colors, technical malfunction
and a "bad" control string is produced e.g. aaaxbbbbyyhwawiwjjjwwm with letters not from a to m.

Write a function printer_error which given a string will output the
error rate of the printer as a string representing a rational whose
numerator is the number of errors and the denominator the length of
the control string. Don't reduce this fraction to a simpler expression.

The string has a length greater or equal to one and contains only letters from a to z.

Examples:
s = "aaabbbbhaijjjm"
error_printer(s) => "0/14"

s = "aaaxbbbbyyhwawiwjjjwwm"
error_printer(s) => "8/22"

Tests:
s = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz"
s = "aaabbbbbbccccccddddddeee"
s = "verylargepiggoesoink"
*/

string error_printer(string colors){
	int count_wrong = 0;
	for(char c : colors){
		if(c > 'm' && c <= 'z')
			count_wrong++;
	}

	return to_string(count_wrong)+"/"+to_string(colors.length());
}

void testFunc(vector<string> v){
	for(string s : v){
		cout << error_printer(s) << "\n";
	}
}

// main function
int main(){
	testFunc({
		"aaabbbbhaijjjm",
		"aaaxbbbbyyhwawiwjjjwwm",
		"aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz",
		"aaabbbbbbccccccddddddeee",
		"verylargepiggoesoink",
	});

	return 0;
}