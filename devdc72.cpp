#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will shift a matrix n times.

You will be given a rectangular matrix called m and must bring
n characters at the end of the matrix to the beginning and shift all other indices over.

Examples:

['a','b','c','d']      ['h','a','b','c']
['1','2','3','4']  =>  ['d','1','2','3']
['c','o','d','e']      ['4','c','o','d']
['b','l','a','h']      ['e','b','l','a']

['d','u','d','e']      ['g','d','u','d']
['i','m','c','o']  =>  ['e','i','m','c']
['d','i','n','g']      ['c','o','d','i']

['h','i']      ['k','h']
['o','k']  =>  ['i','o']
*/

void shiftMatrix(vector<vector<char>>& mat, int n){
	vector<char> unpacked;
	for(auto v : mat)
		for(auto c : v)
			unpacked.push_back(c);
	rotate(unpacked.begin(), unpacked.begin()+unpacked.size()-n,unpacked.end());
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat[i].size();j++)
			mat[i][j] = unpacked[mat[i].size()*i + j];
}


// main function
int main(){
	vector<vector<char>> mat = \
	{
		{'a','b','c','d'},
		{'1','2','3','4'},
		{'c','o','d','e'},
		{'b','l','a','h'}
	};
	
	for(auto v : mat){
		for(auto c : v)
			cout << c << " ";
		cout << "\n";
	}
	
	shiftMatrix(mat, 1);
	
	cout << "\n------------------------\n\n";
	for(auto v : mat){
		for(auto c : v)
			cout << c << " ";
		cout << "\n";
	}
	return 0;
}