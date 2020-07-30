#include <bits/stdc++.h>
using namespace std;

/*
You are an aerial firefighter (someone who drops water on fires from above
in order to extinguish them) and your goal is to work out the minimum amount
of bombs you need to drop in order to fully extinguish the fire (the fire
department has budgeting concerns and you can't just be dropping tons of
bombs, they need that money for the annual Christmas party).

The given string is a 2D plane of random length consisting of two characters:
x representing fire
Y representing buildings

Water that you drop cannot go through buildings and therefore individual
sections of fire must be addressed separately. Your water bombs can only
extinguish contiguous sections of fire up to a width (parameter w).
You must return the minimum number of waterbombs it would take to
extinguish the fire in the string.

Note: all inputs will be valid.

Examples
"xxYxx" and w = 3 --> 2 waterbombs needed
"xxYxx" and w = 1 --> 4
"xxxxYxYx" and w = 5 --> 3
"xxxxxYxYx" and w = 2 --> 5

Tests
waterbombs("xxxxYxYx", 4)
waterbombs("xxYxx", 3)
*/

int waterbombs(string s, int w){
	int count_x = 0, ans = 0;
	
	for(char c : s){
		if(c == 'Y'){
			if(count_x != 0){
				ans++;
				count_x = 0;
			}
		}
		else{
			count_x++;
			if(count_x == w){
				ans++;
				count_x = 0;
			}
		}
	}
	
	if(count_x != 0) ans++;
	
	return ans;
}

void testFunc(vector<pair<string, int>> v){
	for(auto it : v){
		cout << waterbombs(it.first, it.second) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{"xxYxx" ,3},
		{"xxYxx" ,1},
		{"xxxxYxYx" ,5},
		{"xxxxxYxYx" ,2},
		{"xxxxYxYx", 4},
		{"xxYxx", 3},
	});
	return 0;
}