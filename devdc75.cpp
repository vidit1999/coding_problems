#include <bits/stdc++.h>
using namespace std;

/*
Write a function named setAlarm which receives two parameters.
The first parameter, employed, is true whenever you are employed and the second parameter,
vacation is true whenever you are on vacation.

The function should return true if you are employed and not on vacation
(because these are the circumstances under which you need to set an alarm).
It should return false otherwise.

Example:

setalarm(true, true) -> false
setalarm(false, true) -> false
setalarm(false, false) -> false
setalarm(true, false) -> true
*/

bool setAlarm(bool employed = false, bool vacation = false){
	return employed && !vacation;
}

void testFunc(vector<pair<bool, bool>> empVac){
	for(auto entry : empVac)
		if(setAlarm(entry.first, entry.second))
			cout << "Yes\n";
		else
			cout << "No\n";
}

// main function
int main(){
	vector<pair<bool, bool>> empVac = \
	{
		{true, true},
		{false, true},
		{false, false},
		{true, false}
	};
	
	testFunc(empVac);
	return 0;
}