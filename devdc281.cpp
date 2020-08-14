#include <bits/stdc++.h>
using namespace std;

/*
You are given the length and width of a 4-sided polygon.
The polygon can either be a rectangle or a square.

If it is a square, return its area. If it is a rectangle, return its perimeter.

area_or_perimeter(6, 10) --> 32
area_or_perimeter(4, 4) --> 16

Tests

area_or_perimeter(5, 5)
area_or_perimeter(10, 20)
*/

int area_or_perimeter(int a, int b){
	if(a == b)
		return a*a;
	return 2*(a+b);
}

void testFunc(vector<pair<int, int>> v){
	for(auto p : v){
		cout << area_or_perimeter(p.first, p.second) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{6, 10},
		{4, 4},
		{5, 5},
		{10, 20},
	});
	return 0;
}