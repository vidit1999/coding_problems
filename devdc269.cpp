#include <bits/stdc++.h>
using namespace std;

/*
The goal of this challenge is to decompose n! (factorial n) into its prime factors.
The function decomp(n) should return the decomposition of n!
into its prime factors in increasing order of the primes, as a string.
The factorial can be a very big number (4000! has 12674 digits,
n will go from 300 to 4000).

Examples:
n = 12; decomp(12) -> "2^10 * 3^5 * 5^2 * 7 * 11"
since 12! is divisible by 2 ten times, by 3 five times, by 5 two times and by 7 and 11 only once.

n = 22; decomp(22) -> "2^19 * 3^9 * 5^4 * 7^3 * 11^2 * 13 * 17 * 19"
n = 25; decomp(25) -> 2^22 * 3^10 * 5^6 * 7^3 * 11^2 * 13 * 17 * 19 * 23

Prime numbers should be in increasing order. When the exponent of a prime is 1 don't write the exponent.

Tests:
decomp(17)
decomp(5)
decomp(22)
decomp(14)
decomp(25)
*/

// stores the prime factor of numbers
// key => the number, value => map of its prime factor with its respective count
unordered_map<int, unordered_map<int, int>> prime_factor_count;

// merge two prime factorization maps
unordered_map<int, int> merge_maps(unordered_map<int, int> u1, unordered_map<int, int> u2){
	unordered_map<int, int> new_map;
	for(auto it : u1) new_map[it.first] += it.second;
	for(auto it : u2) new_map[it.first] += it.second;
	
	return new_map;
}

// helper function 
void decompHelper(int number){
	for(int i=2;i<=sqrt(number);i++){
		// if the number is divisible by a number(say i)
		// then get its prime factorization
		// get (number/i)'s prime factorization
		// merge them to form a new map
		// set that new map as the prime factorization of number
		if(number%i == 0){
			prime_factor_count[number] = merge_maps(prime_factor_count[i], prime_factor_count[number/i]);
			return;
		}
	}
	
	// it means that the number is a prime number
	prime_factor_count[number][number]++;
}

string decomp(int number){
	prime_factor_count.clear(); // clear the map for every run
	
	for(int i=2;i<=number; i++)
		decompHelper(i);
	
	map<int, int> factor_number;
	for(auto it : prime_factor_count){
		for(auto numbers : it.second){
			factor_number[numbers.first] += numbers.second;
		}
	}
	
	int map_size = 1;
	string factor_string;
	for(auto it : factor_number){
		factor_string += (to_string(it.first) + ((it.second != 1) ? ("^" + to_string(it.second)) : ""));
		if(map_size++ != factor_number.size()) factor_string += " * ";
	}
	
	return factor_string;
}

// main function
int main(){
	cout << decomp(17) << "\n";
	cout << decomp(5) << "\n";
	cout << decomp(22) << "\n";
	cout << decomp(14) << "\n";
	cout << decomp(25) << "\n";
	return 0;
}