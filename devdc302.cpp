#include <bits/stdc++.h>
using namespace std;

/*
Write a function named setAlarm which receives two parameters.
The first parameter, employed, is true whenever you are employed
and the second parameter, vacation is true whenever you are on vacation.

The function should return true if you are employed and not on
vacation (because these are the circumstances under which you
need to set an alarm). It should return false otherwise.

Examples:
setAlarm(true, true) -> false
setAlarm(false, true) -> false
setAlarm(false, false) -> false
setAlarm(true, false) -> true
*/

bool setAlarm(bool employed, bool vacation){
	return employed && !vacation;
}

// main function
int main(){
	cout << setAlarm(true, true) << "\n";
	cout << setAlarm(false, true) << "\n";
	cout << setAlarm(false, false) << "\n";
	cout << setAlarm(true, false) << "\n";
	return 0;
}