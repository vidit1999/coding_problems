#include <bits/stdc++.h>
using namespace std;

/*
Complete the function, which calculates how much you need to tip based on the total
amount of the bill and the service.

You need to consider the following ratings:

Terrible: tip 0%
Poor: tip 5%
Good: tip 10%
Great: tip 15%
Excellent: tip 20%

The rating is case insensitive (so "great" = "GREAT").
If an unrecognized rating is received, then you need to return:
"Rating not recognized" in JavaScript, Python and Ruby...
...or null in Java
...or -1 in C#

Because you're a nice person, you always round up the tip, regardless of the service.

Examples
calculatetip(30, "poor") => 2
calculatetip(20, "hi")=> "Rating Not Recognized"
calculatetip(107.65, "great") => 17

Tests
calculatetip(78, "good") =>
calculatetip(50, "poor") =>
calculatetip(125, "excellent") =>
*/

unordered_map<string, float> services = {
	{"terrible", 0},
	{"poor",  5},
	{"good", 10},
	{"great", 15},
	{"excellent", 20}
};

float calculatetip(float amount, string service){
	string lowercased_service = "";
	for(char c : service)
		lowercased_service += tolower(c);
	
	if(services.find(lowercased_service) != services.end())
		return ceil(amount*services[lowercased_service]/100);
	return -1;
}

// main function
int main(){
	cout << calculatetip(30, "poor") << "\n";
	cout << calculatetip(20, "hi") << "\n";
	cout << calculatetip(107.65, "great") << "\n";
	cout << calculatetip(78, "good") << "\n";
	cout << calculatetip(50, "poor") << "\n";
	cout << calculatetip(125, "excellent") << "\n";
	return 0;
}