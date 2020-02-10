#include <bits/stdc++.h>
using namespace std;

/*

The aim of this [challenge] is to decompose n!(factorial n) into its prime factors.
Prime numbers should be in increasing order. When the exponent of a prime number is 1, don't print the exponent.

Examples:
n = 22; decomp(22) -> "2^19 * 3^9 * 5^4 * 7^3 * 11^2 * 13 * 17 * 19"
n = 25; decomp(25) -> "2^22 * 3^10 * 5^6 * 7^3 * 11^2 * 13 * 17 * 19 * 23"

Explanation:
n = 12; decomp(12) -> "2^10 * 3^5 * 5^2 * 7 * 11"
12! is divisible by 2 ten times, by 3 five times, by 5 two times and by 7 and 11 only once.

*/

// factorsOfNum(16,2,factorDecompose) -> 


void factorsOfNum(int num1, int num2, unordered_map<int, map<int,int>>& factorDecompose){
	map<int, int> factors = factorDecompose[num1/num2];
	map<int,int> factorOfnum1;
	factorOfnum1 = factors;
	factorOfnum1[num2]++;
	factorDecompose[num1] = factorOfnum1;
}

void createFactorsFromTwo(map<int, int>& factorOfnum1, map<int,int> factorOfnum2){
	for(auto it : factorOfnum2){
		factorOfnum1[it.first] += it.second;
	}
}

void factirialDecomposition(int n){
	vector<int> primes;
	unordered_map<int, map<int,int>> factorDecompose;
	for(int i=2;i<=n;i++){
		bool isPrime = true;
		for(int p : primes){
			if(i%p==0){
				isPrime = false;
				factorsOfNum(i,p,factorDecompose);
				break;
			}
		}
		if(isPrime){
			factorDecompose[i][i] = 1;
			primes.push_back(i);
		}
	}
	map<int, int> factors;
	for(auto it : factorDecompose){
		createFactorsFromTwo(factors, it.second);
	}
	for(auto it : factors){
		if(it.second > 1)
			cout << it.first << "^" << it.second << " * ";
		else
			cout << it.first << " * ";
	}
	cout << "1";
}

// main function
int main(){
	int n = 25;
	factirialDecomposition(n);
	return 0;
}