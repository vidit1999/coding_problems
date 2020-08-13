#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will charge driving students based on the
amount of time they spent in their lessons. This particular
school charges for lessons as follows:

Time                            Cost
************************************
Up to 1st hour                   $30
Every subsequent half hour**     $10

** Subsequent charges are calculated by rounding up to nearest half hour.

For example, if student X has a lesson for 1hr 20 minutes,
he will be charged $40 (30+10) for 1 hr 30 mins and if he
has a lesson for 10 minutes, he will be charged $30 for the full hour.

Out of the kindness of its heart, the driving school also
provides a 5 minutes grace period. So, if student X were
to have a lesson for 65 minutes, he will only have to pay
for an hour. Lessons under 5 minutes are just talks,
so they should be considered free.

For a given lesson time in minutes (min), write a
function price to calculate how much the lesson costs.

Tests
cost(84)
cost(102)
cost(273)
*/

int costs(int time_min){
	// if time is less than 5 minutes return 0
	if(time_min <= 5) return 0;

	int total_cost = 0;

	time_min -= 60; // for first hour
	total_cost += 30;

	// time left is less than 5 minutes then no charge
	if(time_min < 5) return total_cost;

	// for every subsequent hour charge is $10
	// and there is grace of 5 minitus
	while(time_min > 5){
		time_min -= 60;
		total_cost += 10;
	}

	return total_cost;
}

// main function
int main(){
	cout << costs(80) << "\n";
	cout << costs(90) << "\n";
	cout << costs(10) << "\n";
	cout << costs(60) << "\n";
	cout << costs(65) << "\n";
	cout << costs(53) << "\n";
	cout << costs(4) << "\n";
	cout << costs(84) << "\n";
	cout << costs(102) << "\n";
	cout << costs(273) << "\n";
	cout << costs(70) << "\n";
	return 0;
}