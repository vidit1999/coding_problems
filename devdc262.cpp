#include <bits/stdc++.h>
using namespace std;

/*
No one enjoys carrying around spare change.
And to avoid all that jingling it's absolutely necessary
to have an efficient algorithm to calculate the minimum
number of coins needed to pay for something. So given a
set of coin denominations determine the fewest number of
coins required to add up to a given amount.
Coin denominations WILL NOT be standard.

Example
US Currency includes the penny, nickel, dime and
quarter or the coins with denominations: [1, 5, 10, 25]
If I were to ask you to make 75 cents you would
just return 3 since 75 cents can be made with 3 quarters.

Denominations:
coins1={1,5,10,25};
coins2={1,2,5,10,20,50};

Tests:
coins1(123)
coins2(123)
coins1(75)
coins2(75)
*/

int minCoinChange(vector<int> coins, int amount){
	if(amount == 0)
		return 0;

	int result = INT_MAX;

	for(int coin : coins){
		if(coin <= amount){
			int temp_result = minCoinChange(coins, amount-coin);
			if(temp_result != INT_MAX && temp_result + 1 < result)
				result = temp_result + 1;
		}
	}

	return result;
}

int minCoinChangeDP(vector<int> coins, int amount){
	int table[amount+1];
	table[0] = 0;

	for(int i=1;i<=amount;i++)
		table[i] = INT_MAX;

	for(int i=1;i<=amount;i++){
		for(int coin : coins){
			if(coin <= i){
				int temp_result = table[i-coin];
				if(temp_result != INT_MAX && temp_result + 1 < table[i])
					table[i] = temp_result + 1;
			}
		}
	}

	return table[amount];
}

// main function
int main(){
	cout << minCoinChangeDP({25,10,5,1}, 75) << "\n";
	return 0;
}