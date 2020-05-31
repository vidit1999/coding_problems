#include <bits/stdc++.h>
using namespace std;

/*
In John's car the GPS records every s seconds the distance traveled from an origin point
(distances are measured in an arbitrary but consistent unit). For example,
below is part of a record with s = 15:
x = [0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25]

The sections are:
0.0-0.19, 0.19-0.5, 0.5-0.75, 0.75-1.0, 1.0-1.25, 1.25-1.50, 1.5-1.75, 1.75-2.0, 2.0-2.25

We can calculate John's average hourly speed in each section:
[45.6, 74.4, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0]

Given s and x, the task is to return as an integer the floor of the maximum average
speed per hour obtained on the sections of x. If x length is less than or equal to
1 return 0 since the car didn't move.

Tests:
1
x = [0.0, 0.02, 0.36, 0.54, 0.72, 0.9, 1.08, 1.26, 1.44, 1.62, 1.8];
s = 17;

2
x = [0.0, 0.01, 0.36, 0.6, 0.84, 1.05, 1.26, 1.47, 1.68, 1.89, 2.1, 2.31, 2.52, 2.73, 2.94, 3.15];
s = 14;

Good luck, you can use (3600 * delta_distance) / s to calculate speed!
*/

int maxAverageSpeed(vector<float> x, int s){
	if(x.size() <= 1)
		return 0;
	
	float maxAvgSpeed = 0;
	for(int i=1;i<x.size();i++)
		maxAvgSpeed = max(maxAvgSpeed, floor(3600*abs(x[i]-x[i-1])/s));
	
	return maxAvgSpeed;
}

// main function
int main(){
	cout << maxAverageSpeed({0.0, 0.19, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25}, 15) << "\n";
	cout << maxAverageSpeed({0.0, 0.02, 0.36, 0.54, 0.72, 0.9, 1.08, 1.26, 1.44, 1.62, 1.8}, 17) << "\n";
	cout << maxAverageSpeed({0.0, 0.01, 0.36, 0.6, 0.84, 1.05, 1.26, 1.47, 1.68, 1.89, 2.1, 2.31, 2.52, 2.73, 2.94, 3.15}, 14) << "\n";
	return 0;
}