#include <iostream>
#include <vector>
using namespace std;

/*
You're a buyer/seller and your business is at stake. You need to make profit...
Or at least, you need to lose the least amount of money! Knowing a list of prices for buy/sell operations,
you need to pick two of them. Buy/sell market is evolving across time and the list represent this
evolution. First, you need to buy one item, then sell it later. Find the best profit you can do.

Input:
A list of prices (integers), of length 2 or more.

Output:
The result of the best buy/sell operation, as an integer.

Example:
Given an array of prices [3, 10, 8, 4], the best profit you could make would be 7
because you buy at 3 first, then sell at 10.

Tests:
max_profit([10, 7, 5, 8, 11, 9])
max_profit([3, 4])
max_profit([9, 9])
max_profit([10, 7, 5, 4, 1])
*/

int max_profit(vector<int> prices){
    // stores the maximum profit made so far
    int maxProfitSoFar = prices[1] - prices[0];

    // stores the minimum price seen so far
    int minPriceSoFar = min(prices[0], prices[1]);

    for(int i = 2; i < prices.size(); i++){
        // maximum profit will be the maximum of
        // (current price - minimum price seen before) and maximum profit so far
        maxProfitSoFar = max(prices[i] - minPriceSoFar, maxProfitSoFar);

        // minimum price will be minimum of current price and minimum price so far
        minPriceSoFar = min(prices[i], minPriceSoFar);
    }

    return maxProfitSoFar;
}

// main function
int main(){
    cout << max_profit({3, 10, 8, 4}) << "\n"; // output -> 7
    cout << max_profit({10, 7, 5, 8, 11, 9}) << "\n"; // output -> 6
    cout << max_profit({3, 4}) << "\n"; // output -> 1
    cout << max_profit({9, 9}) << "\n"; // output -> 0
    cout << max_profit({10, 7, 5, 4, 1}) << "\n"; // output -> -1
    return 0;
}