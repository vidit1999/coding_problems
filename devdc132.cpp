#include <bits/stdc++.h>
using namespace std;

/*
A friend of mine takes a sequence of numbers from 1 to n (where n > 0).
Within that sequence, he chooses two numbers, a and b.
He says that the product of a and b should be equal to the sum of all numbers in the sequence, excluding a and b.
Given a number n, could you tell me the numbers he excluded from the sequence?
The function takes the parameter: n (n is always strictly greater than 0)
and returns an array or a string (depending on the language) of the form:

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or or [{a, b}, ...]
with all (a, b) which are the possible removed numbers in sequence 1 to n.

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ...will be sorted in increasing order of the "a".

It happens that there are several possible (a, b). The function returns an
empty array (or an empty string) if no possible numbers are found which will
prove that my friend has not told the truth! (Go: in this case return nil).

Examples
removNb(26) should return [(15, 21), (21, 15)]
or
removNb(26) should return { {15, 21}, {21, 15} }
or
removeNb(26) should return [[15, 21], [21, 15]]
or
removNb(26) should return [ {15, 21}, {21, 15} ]
or
removNb(26) should return "15 21, 21 15"
or
in C:
removNb(26) should return **an array of pairs {{15, 21}{21, 15}}**
tested by way of strings.
*/

vector<pair<int, int>> removNb(int n){
	if(n <= 1)
		return {};
	
	set<pair<int, int>> numberPair;
	int sum = n*(n+1)/2;
	
	for(int a=1;a<=n;a++){
		if((sum - a)%(a+1) == 0){
			int b = (sum - a) / (a+1);
			if(
				b >= 1 &&
				b <= n &&
				b != a &&
				numberPair.find({a, b}) == numberPair.end() &&
				numberPair.find({b, a}) == numberPair.end()
			){
				numberPair.insert({a, b});
				numberPair.insert({b, a});
			}
		}
	}
	
	return {numberPair.begin(), numberPair.end()};
}

// main function
int main(){
	for(auto it : removNb(26))
		cout << it.first << " " << it.second << "\n";
	return 0;
}