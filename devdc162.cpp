#include <bits/stdc++.h>
using namespace std;

/*
You work as a taxi dispatcher. People will contact you to order a taxi,
informing you of their pickup and drop-off times. Taxis can only service one customer at a time.
They can pick up a new customer 1 time unit after it has dropped off a previous customer.
What is the minimum number of taxis you need to service all requests?

Constraints:
Let N be the number of customer requests:
N is an integer in the range [1, 100k]
All times will be integers in range [1, 10k]
Let PU be the time of pickup and DO be the time of drop-off
For each request: PU < DO
The input list is NOT sorted.

Examples:
Two customers, overlapping schedule. Two taxis needed.
requests = [(1, 4), (2, 6)]
min_num_taxis(requests) # => 2

Two customers, no overlap in schedule. Only one taxi needed.
requests = [(1, 4), (5, 9)]
min_num_taxis(requests) # => 1

Tests:
1: [(1,4)]
2: [(1,4), (5, 9)]
3: [(1,4), (2, 9), (3, 6), (5, 8)]
*/

int min_num_taxis(vector<pair<int, int>> schedule){
	int taxi_count = 1;
	
	sort(schedule.begin(), schedule.end());
	
	int end_time = schedule[0].second;
	
	for(int i=1;i<schedule.size();i++){
		if(schedule[i].first <= end_time)
			taxi_count++;
		end_time = max(end_time, schedule[i].second);
	}
	
	return taxi_count;
}

void testFunc(vector<vector<pair<int, int>>> v){
	for(auto schedule : v){
		cout << min_num_taxis(schedule) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{{1, 4}, {2, 6}},
		{{1, 4}, {5, 9}},
		{{1,4}},
		{{1,4}, {5, 9}},
		{{1,4}, {2, 9}, {3, 6}, {5, 8}}
	});
	return 0;
}