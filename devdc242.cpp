#include <bits/stdc++.h>
using namespace std;

/*
Given three integers a ,b ,c, return the largest number obtained
after inserting the following operators and brackets: +, *, () In other words ,
try every combination of a,b,c with [*,+,()] , and return the highest number.

Here's an example:
1 * (2 + 3) = 5
1 * 2 * 3 = 6
1 + 2 * 3 = 7
(1 + 2) * 3 = 9 <-- So the maximum value that you can obtain is 9.

Tests
expression_matter(5, 1, 3)
expression_matter(3, 5, 7)
expression_matter(5, 6, 1)
expression_matter(1, 6, 1)
expression_matter(2, 6, 1)
*/

int expression_matter(int a, int b, int c){
	vector<int> combinations = {
		a+b+c,
		a*b*c,
		a+b*c,
		a*b+c,
		(a+b)*c,
		a*(b+c)
	};
	return *max_element(combinations.begin(), combinations.end());
}

// main function
int main(){
	cout << expression_matter(1, 2, 3) << "\n";
	cout << expression_matter(5, 1, 3) << "\n";
	cout << expression_matter(3, 5, 7) << "\n";
	cout << expression_matter(5, 6, 1) << "\n";
	cout << expression_matter(1, 6, 1) << "\n";
	cout << expression_matter(2, 6, 1) << "\n";
	return 0;
}