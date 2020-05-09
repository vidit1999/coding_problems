#include <bits/stdc++.h>
using namespace std;

/*
Given an array of values and a number of beggars, you are supposed to return an array
with the sum of what each beggar brings home, assuming they all take regular turns, from the first to the last.

For example: [1,2,3,4,5] for 2 beggars will return a result of [9,6],
as the first one takes [1,3,5], the second collects [2,4].

The same array with 3 beggars would have in turn have produced a
better outcome for the second beggar: [5,7,3], as they will respectively take [1,4], [2,5] and [3].

Also note that not all beggars have to take the same amount of "offers",
meaning that the length of the array is not necessarily a multiple of n;
length can be even shorter, in which case the last beggars will, of course, take nothing (0).
*/

vector<int> beggarsAmount(vector<int> values, int number){
	vector<int> beggars(number, 0);
	
	for(int i=0; i<number; i++){
		for(int j=i; j<values.size(); j+=number)
			beggars[i] += values[j];
	}
	
	return beggars;
}

// main function
int main(){
	for(int result : beggarsAmount({1,2,3,4,5}, 3))
		cout << result << "\n";
	return 0;
}