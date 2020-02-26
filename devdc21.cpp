#include <bits/stdc++.h>
using namespace std;

/*
The function will accept an input of non-negative integers.
If it is zero, it just returns "now". Otherwise, the duration is
expressed as a combination of years, days, hours, minutes, and seconds, in that order.

The resulting expression is made of components like 4 seconds, 1 year, etc.
The unit of time is used in plural if the integer is greater than 1.
The components are separated by a comma and a space (", "), except the last component which
is separated by " and ", just like it would be written in English.
For the purposes of this challenge, a year is 365 days and a day is 24 hours.

Note that spaces are important.

The challenge is much easier to understand through example:
format_duration(62) # returns "1 minute and 2 seconds"
format_duration(3662) # returns "1 hour, 1 minute and 2 seconds"
*/


// helper function for formatting duration
// type_time = 31536000 for year
// type_time = 86400 for day
// type_time = 3600 for hour
// type_time = 60 for minute
// type_time = 1 for second
long formatted_duration_helper(long duration,long type_time, string& formated){
    string type_string;
    if(type_time == 31536000)
        type_string = "year";
    else if(type_time == 86400)
        type_string = "day";
    else if(type_time == 3600)
        type_string = "hour";
    else if(type_time == 60)
        type_string = "minute";
    else if(type_time == 1)
        type_string = "second";

    if(duration >= type_time){
        bool lastFlag = false;
        if(duration % type_time == 0){
            lastFlag = true;
        }
        if(formated.size() > 0 && lastFlag){
            formated = formated.substr(0,formated.size()-2);
            formated += " and ";
        }
        formated += (to_string(duration/type_time) + " " + type_string);
        if(duration/type_time > 1)
            formated += "s";
        duration %= type_time;
        if(duration > 0)
            formated += ", ";
    }
    return duration;
}

string format_duration(long duration){
    string formated = "";
    duration = formatted_duration_helper(duration,31536000,formated);
    duration = formatted_duration_helper(duration,86400,formated);
    duration = formatted_duration_helper(duration,3600,formated);
    duration = formatted_duration_helper(duration,60,formated);
    duration = formatted_duration_helper(duration,1,formated);
    return formated;
}

// main function
int main(){
    cout << format_duration(62) << "\n";
    cout << format_duration(3662) << "\n";
    cout << format_duration(3600) << "\n";
    return 0;
}