#include <bits/stdc++.h>
using namespace std;

/*
Mr. Square is going on holiday. He wants to bring 2 of his favorite squares with him,
so he put them in his rectangle suitcase.

Write a function that, given the size of the squares and the suitcase,
return whether the squares can fit inside the suitcase.

fit_in(a,b,m,n)
a,b are the sizes of the squares
m,n are the sizes of the suitcase

Example
fit_in(1,2,3,2) should return True
fit_in(1,2,2,1) should return False
fit_in(3,2,3,2) should return False
fit_in(1,2,1,2) should return False
*/

bool fit_in(int a, int b, int m, int n){
	return ((a + b) <= max(m, n)) && (max(a, b) <= min(m, n));
}

void testFunc(vector<vector<int>> v){
	for(auto it : v){
		if(fit_in(it[0], it[1], it[2], it[3]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	testFunc({
		{1,2,3,2},
		{1,2,2,1},
		{3,2,3,2},
		{1,2,1,2}, 
	});
	return 0;
}