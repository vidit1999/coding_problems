#include <bits/stdc++.h>
using namespace std;

/*
What is your favorite day of the week?
Check if it's the most frequent
day of the week in the year.

You are given a year as an integer (e.g. 2001).
You should return the most frequent
day(s) of the week in that year.

Input: Year as an int.

Output: The list of most frequent
days in the Gregorian calendar year.

Examples:
most_frequent_days(2427) == ['Friday']
most_frequent_days(2185) == ['Saturday']
most_frequent_days(2860) == ['Thursday', 'Friday']

Tests:
most_frequent_days(1770)
most_frequent_days(1785)
most_frequent_days(1984)
most_frequent_days(2000)
*/

string dayNumToString(int day){
	switch(day){
		case 0 : return "Sunday";
		case 1 : return "Monday";
		case 2 : return "Tuesday";
		case 3 : return "Wednesday";
		case 4 : return "Thursday";
		case 5 : return "Friday";
		case 6 : return "Saturday";
	}

	return "";
}

bool isLeap(int year){
	if(year%400 == 0)
		return true;
	
	if(year%100 == 0)
		return false;
	
	if(year%4 == 0)
		return true;

	return false;
}

string dayOfWeek(int year, int month, int day){
	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

	if(month < 3)
		year--;

	return dayNumToString((year + year/4 - year/100 + year/400 + t[month-1] + day) % 7);
}

vector<string> most_frequent_days(int year){
	vector<string> ans = {dayOfWeek(year, 1, 1)};
	
	if(isLeap(year))
		ans.push_back(dayOfWeek(year, 1, 2));
	
	return ans;
}

void testFunc(vector<int> years){
	for(int year : years){
		auto ans = most_frequent_days(year);
		
		for(auto s : ans){
			cout << s << " ";
		}
		
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		2427,
		2185,
		2860,
		1770,
		1785,
		1984,
		2000,
	});
	return 0;
}