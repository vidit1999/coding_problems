#include <bits/stdc++.h>
using namespace std;

/*
If the first day of the month is a Friday, it is likely that the month will have
an Extended Weekend. That is to say, it could have five Fridays, five Saturdays and five Sundays.

In this Kata, you will be given a start year a and an end year b(1000 <= a <= b <= 275760).
Your task will be to find months that have extended weekends and return:

The first and last month in the range that has an extended weekend
The number of months that have extended weekends in the range,
inclusive of start year and end year.
If, there is no Extended Weekend, just return ["","",0].

Example
solve(2016,2020) = ("Jan","May",5).
The months are: Jan 2016, Jul 2016, Dec 2017, Mar 2019, May 2020

Tests
solve(2016,2020)
solve(1900,1950)
solve(1800,2500)
solve(1000,275760)
*/

unordered_map<int, string> month_num_map = {
	{1, "Jan"},
	{2, "Feb"},
	{3, "Mar"},
	{4, "Apr"},
	{5, "May"},
	{6, "Jun"},
	{7, "Jul"},
	{8, "Aug"},
	{9, "Sep"},
	{10, "Oct"},
	{11, "Nov"},
	{12, "Dec"}
};

bool isLeapYear(int n){
	if(n%400 == 0) return true;
	if(n%100 == 0) return false;
	if(n%4 == 0) return true;
	return false;
}

// tomohiko sakamoto algorithm 
int day_of_the_week(int y, int m, int d){
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (m < 3)
        y -= 1;
    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

int getMonthDateCount(int year, int month){
    if(isLeapYear(year) && month == 2) return 29;
    switch(month){
        case 1 : return 31;
        case 2 : return 28;
        case 3 : return 31;
        case 4 : return 30;
        case 5 : return 31;
        case 6 : return 30;
        case 7 : return 31;
        case 8 : return 31;
        case 9 : return 30;
        case 10 : return 31;
        case 11 : return 30;
        case 12 : return 31;
    }
    return -1;
}

bool checkMonthExtended(int year, int month){
    int count_friday = 0, count_saturday = 0, count_sunday = 0;
    int s = 1;
    int e = getMonthDateCount(year, month);

    for(int i=s; i<=e; i++){
        if(day_of_the_week(year, month, i) == 5) count_friday++;
        if(day_of_the_week(year, month, i) == 6) count_saturday++;
        if(day_of_the_week(year, month, i) == 0) count_sunday++;
    }

    return (
        (count_friday >= 5) &&
        (count_saturday >= 5) &&
        (count_sunday >= 5)
    );
}

void solve(int a, int b){
	string start = "", end = "";
	int count = 0;
	vector<pair<string, int>> month_year;

	for(int year=a; year<=b; year++){
		for(int month=1; month<=12; month++){
			if(checkMonthExtended(year, month)){
				if(count == 0){
					start = month_num_map[month];
				}
				end = month_num_map[month];
				count++;
				month_year.push_back({end, year});
			}
		}
	}

	cout << start << ", " << end << ", " << count << "\n";

	for(auto it : month_year){
		cout << "(" << it.first << ", " << it.second << "), ";
	}

	cout << "\n";
}

void testFunc(vector<pair<int, int>> v){
	for(auto p : v){
		solve(p.first, p.second);
	}
}

// main function
int main(){
	testFunc({
		{2016,2020},
		{1900,1950},
		{1800,2500},
        {1000,275760}
	});
	return 0;
}