#include <bits/stdc++.h>
using namespace std;

/*
Friday 13th or Black Friday is considered as an unlucky day.
Calculate how many unlucky days are in the given year.

Can you find the number of Friday 13th in the given year? Good luck!

Input: Year as an integer.

Output: Number of Black Fridays in the year as an integer.

Examples:

unluckyDays(2015) == 3
unluckyDays(1986) == 1
*/

// return day of a week
// sunday is 0
// monday is 1 and so on...
// saturday is 6
int dayOfWeek(int day, int month, int year){
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3)
        year -= 1;
    return ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7);
}

// returns number of unlucky days in year
int unluckyDays(int year){
    int count = 0;
    for(int i=1;i<=12;i++){
        if(dayOfWeek(13,i,year)==5)
            count++;
    }
    return count;
}

// main function
int main(){
    cout << unluckyDays(2015) << "\n";
    cout << unluckyDays(1986) << "\n";
    return 0;
}