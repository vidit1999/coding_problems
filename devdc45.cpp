#include <bits/stdc++.h>
using namespace std;

/*
implement a change function that will accept an integer parameter that represents cents.
The function should return the optimal change using the least number of coins.
The function should also return a key for each coin of US currency
(specifically 25¢, 10¢, 5¢, and 1¢ coins). The value of each coin should represent
the count of each coin in the change. The value for each coin that is not included should return 0.

Ex.
change(31)
{ 25 => 1, 10 => 0, 5 => 1, 1 => 1 }
*/

unordered_map<int, int> change(int cents){
	unordered_map<int, int> optimalChange;
	vector<int> available = {25, 10, 5, 1};
	for(int coin : available){
		int number = 0;
		number += (cents/coin);
		cents %= coin;
		optimalChange[coin] = number;
	}
	return optimalChange;
}

// main function
int main(){
	unordered_map<int, int> changes = change(31);
	for(auto it : changes){
		cout << it.first << " -- " << it.second << "\n";
	}
	return 0;
}