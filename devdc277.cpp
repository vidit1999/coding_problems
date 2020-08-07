#include <bits/stdc++.h>
using namespace std;

/*
You've just moved into a perfectly straight street with exactly n
identical houses on either side of the road. Naturally, you would
like to find out the house number of the people on the other side
of the street. The street looks something like this:

1|   |6
3|   |4
5|   |2

Evens increase on the right; odds decrease on the left.
House numbers start at 1 and increase without gaps.
When n = 3, 1 is opposite 6, 3 opposite 4, and 5 opposite 2.

Given your house number address and length of street n,
give the house number on the opposite side of the street.

Examples
over_the_road(address, n)

over_the_road(1, 3) = 6
over_the_road(3, 3) = 4

Tests
over_the_road(3, 5)
over_the_road(7, 11)
*/

int over_the_road(int address, int n){
	return 2*n + 1 - address;
}

// main function
int main(){
	cout << over_the_road(1, 3) << "\n";
	cout << over_the_road(3, 3) << "\n";
	cout << over_the_road(3, 5) << "\n";
	cout << over_the_road(7, 11) << "\n";
	return 0;
}