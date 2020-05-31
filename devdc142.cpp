#include <bits/stdc++.h>
using namespace std;

/*
Given a long number, write a function to return all possible pairs of addends and the sum of each pair.

For example, 12,345: all of the addends from that number are:
[ 1 + 2, 1 + 3, 1 + 4, 1 + 5, 2 + 3, 2 + 4, 2 + 5, 3 + 4, 3 + 5, 4 + 5 ]

Therefore the result must be:
[ 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 ]

Test Cases
156
81596
3852
3264128
999999
*/

vector<int> addends(int number){
	vector<int> ans;
	vector<int> temp; // stores the digits seen so far
	
	while(number || ans.empty()){
		int lastDigit = number%10;
		for(int digit : temp)
			ans.push_back(digit + lastDigit);
		temp.push_back(lastDigit);
		number /= 10;
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}

void testFunc(vector<int> numbers){
	for(int number : numbers){
		for(int i : addends(number))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		12345,
		156,
		81596,
		3852,
		3264128,
		0,
		10,
		320,
		999999
	});
	return 0;
}