#include <bits/stdc++.h>
using namespace std;

/*
In an attempt to boost sales, the manager of the pizzeria you work at
has devised a new pizza rewards system. Although, he isn't exactly sure what he wants
the variables to be. The rewards system may change in the future.
Your manager wants you to implement a function that, given a dictionary of customers,
a minimum number of orders, and a minimum order value,
returns a set of the customers who are eligible for a reward.

Customers in the dictionary are represented as:
{ 'customerName' : [list_of_order_values_as_integers] }

Test 1:
Make at least 5 orders of at least 20$ each and get a free pizza!

min_orders = 5
min_price = 20
customers = {
'John Doe' : [22, 30, 11, 17, 15, 52, 27, 12], 
'Jane Doe' : [5, 17, 30, 33, 40, 22, 26, 10, 11, 45]
}

Test 2:
Make at least 2 orders of at least 50$ each and get a free pizza!

min_orders = 2
min_price = 50
customers = {
'Joey Bonzo' : [22, 67, 53, 29],
'Jennifer Bonzo' : [51, 19]
}

Test 3:
Make at least 3 orders of at least 15$ each and get a free pizza!

min_orders = 3
min_price = 15
customers = {
'Natsumi Sakamoto' : [15, 15, 14],
'Gorou Hironaka' : [15, 15, 15],
'Shinju Tanabe' : [120, 240]
}
*/

vector<string> rewardCustomers(unordered_map<string, vector<int>> customers, int min_orders, int min_price){
	vector<string> rewarded = {};
	for(auto customer : customers){
		int count = 0;
		for(auto price : customer.second)
			if(price >= min_price)
				count++;
		if(count >= min_orders)
			rewarded.push_back(customer.first);
	}
	return rewarded;
}

// main function
int main(){
	unordered_map<string, vector<int>> customers = \
	{
		{"Natsumi Sakamoto", {15, 15, 14}},
		{"Gorou Hironaka", {15, 15, 15}},
		{"Shinju Tanabe", {120, 240}}
	};
	int min_price = 15, min_orders = 3;
	
	for(auto s : rewardCustomers(customers, min_orders, min_price))
		cout << s << "\n";
	return 0;
}