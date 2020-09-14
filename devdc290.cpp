#include <bits/stdc++.h>
using namespace std;

/*
Given time in 24-hour format, convert it to words.

For example:
13:00 = one o'clock 
13:09 = nine minutes past one 
13:15 = quarter past one 
13:29 = twenty nine minutes past one
13:30 = half past one 
13:31 = twenty nine minutes to two
13:45 = quarter to two 
00:48 = twelve minutes to one
00:08 = eight minutes past midnight
12:00 = twelve o'clock
00:00 = midnight

Note: If minutes == 0, use 'o'clock'.
If minutes <= 30, use 'past',
and for minutes > 30, use 'to'. 

Good luck!
Tests:
07:01
01:59
12:01
00:01
11:31
23:31
*/

unordered_map<int, string> hour_map = {
	{0, "midnight"},
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
	{10, "ten"},
	{11, "eleven"},
	{12, "twelve"}
};

unordered_map<int, string> minute_map = {
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
	{10, "ten"},
	{11, "eleven"},
	{12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "quarter"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {21, "twenty one"},
	{22, "twenty two"},
	{23, "twenty three"},
	{24, "twenty four"},
	{25, "twenty five"},
	{26, "twenty six"},
	{27, "twenty seven"},
	{28, "twenty eight"},
	{29, "twenty nine"},
    {30, "half"}
};

string timeWords(pair<string, string> hour_minute){
	int hour = stoi(hour_minute.first), minute = stoi(hour_minute.second);

    if(minute == 0){
        if(hour == 0)
            return "midnight";
        if(hour == 12){
            return hour_map[12] + " o'clock";
        }
        return hour_map[hour%12] + " o'clock";
    }
    
    string middle = " past ";
    
    if(minute > 30){
        minute = 60 - minute;
        hour += 1;
        middle = " to ";
    }

    return (
        minute_map[minute] +
        ((minute == 30)? "" : (minute > 1)? " minutes" : " minute") + 
        middle +
        hour_map[(hour == 12)? 12 : hour%12]
    );
}

void testFunc(vector<pair<string, string>> v){
    for(auto p : v){
        cout << timeWords(p) << "\n";
    }
}

// main function
int main(){
    vector<pair<string, string>> times = {
        {"13", "00"},
        {"13", "09"},
        {"13", "15"},
        {"13", "29"},
        {"13", "30"},
        {"13", "31"},
        {"13", "45"},
        {"00", "48"},
        {"00", "08"},
        {"12", "00"},
        {"00", "00"},
        {"07", "01"},
        {"01", "59"},
        {"12", "01"},
        {"00", "01"},
        {"11", "31"},
        {"23", "31"},
    };
    testFunc(times);
	return 0;
}