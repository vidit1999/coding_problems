#include <bits/stdc++.h>
using namespace std;

/*
You've just returned from a road trip and are curious about your car's fuel
consumption during the trip. Unfortunately, you didn't reset the counter before leaving home.
You do know the average consumption of your car and the previous distance you have traveled in that vehicle.

Write a function that takes two pairs of input (before, after) and returns the calculated
average fuel consumption of your car during your trip, rounded to the first decimal place.

Both pairs consist of two valid numbers:

average fuel consumption of the car (l/100km, float)
previous distance traveled (km, integer)

Example:
BEFORE                   AFTER                  DURING
avg. cons, distance     avg. cons, distance         avg. cons
[l/100km]    [km]       [l/100km]    [km]           [l/100km]
[   7.9  ,   100  ]  ,  [   7.0  ,   200  ]    -->     6.1
[   7.9  ,   500  ]  ,  [   7.0  ,   600  ]    -->     2.5
[   7.9  ,   100  ]  ,  [   7.0  ,   600  ]    -->     6.8
*/

float avgFuelCons(pair<float, float> before, pair<float, float> after){
	return round((after.first*after.second - before.first*before.second)*10 / (after.second - before.second))/10;
}

// main function
int main(){
	cout << avgFuelCons({7.9, 100}, {7.0, 600}) << "\n";
	return 0;
}