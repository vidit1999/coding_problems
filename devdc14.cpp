#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, return a strictly increasing sequence of
numbers so that the sum of the squares is equal to n².

If there are multiple solutions, return the result with the largest possible value:

For example: decompose(11) must return [1,2,4,10].

Note: there are actually two ways to decompose 11²,
11² = 121 = 1 + 4 + 16 + 100 = 1² + 2² + 4² + 10² but you shouldn't return [2,6,9],
since 9 is smaller than 10.

Hint: Very often will xk be n-1.
*/

// helper function for decompose
bool decomposeHelper(int target, int number, vector<int>& decomposed){
    if(target == 0){
        return true;
    }
    if(target < 0 || (number == 1 && target > 1)){
        return false;
    }

    for(int i=number-1;i>=1;i--){
        if(decomposeHelper(target-i*i,i,decomposed)){
			decomposed.push_back(i);
            return true;
		}
    }
	return false;
}

// decomposes a number and returns them as a vector
vector<int> decompose(int number){
    vector<int> v;
	decomposeHelper(number*number, number, v);
	return v;
}

// test function
// prints the decomposed values of numbers from 1 to testLast
void testFunc(int testLast){
	for(int i=1;i<=testLast;i++){
		cout << "Number : " << i << " -- decomposed -- ";
		vector<int> v = decompose(i);
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
    testFunc(100);
    return 0;
}