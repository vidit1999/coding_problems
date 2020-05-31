#include <bits/stdc++.h>
using namespace std;

/*
The Pony Express was a mail service that operated from 1859-60 in the United States.
It was made completely obsolete by the intercontinental telegraph.

There were a number of stations where a rider would stop to switch to a fresh horse,
or pass the mail bag along to another rider to continue the trek.

stations is an array/list of distances in miles from one station to the next along the route.

Implement a riders function, to return how many riders it would take to get from point A to point B.
Riders will never agree to riding more than 100 miles.

example: stations = [43, 23, 40, 13]
output: 2 riders
*/

int riders(vector<int> stations){
	float sum = 0;
	for(int i : stations)
		sum += i;
	return ceil(sum/100);
}


// main function
int main(){
	cout << riders({43, 23, 40, 13}) << "\n";
	return 0;
}