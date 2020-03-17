#include <bits/stdc++.h>
using namespace std;

/*
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]

Given an array of n * x, return the array elements arranged from outermost elements to the middle element,
traveling clockwise. Do not sort the elements from lowest to highest, instead traverse the 2-D array
in a clockwise, snailshell pattern.

These examples will clarify the challenge:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

An empty matrix would be represented as [[]].

Below are some matrices to test your code on. Good luck, have fun!

(snail([[]]));

(snail([[1]]));

(snail([[1, 2, 3], 
        [4, 5, 6], 
        [7, 8, 9]));

(snail([[1, 2, 3, 4, 5], 
        [6, 7, 8, 9, 10], 
        [11, 12, 13, 14, 15], 
        [16, 17, 18, 19, 20], 
        [21, 22, 23, 24, 25]]));

(snail([[1, 2, 3, 4, 5, 6],
        [20, 21, 22, 23, 24, 7], 
        [19, 32, 33, 34, 25, 8], 
        [18, 31, 36, 35, 26, 9], 
        [17, 30, 29, 28, 27, 10], 
        [16, 15, 14, 13, 12, 11]]));

*/

vector<int> snailSort(vector<vector<int>> arr){
	int n = arr.size();
	int x = arr[0].size();
	vector<int> sorted;
	int k = 0, l = 0;
	while(k < x && l < n){
		for(int i=l;i<n;i++)
			sorted.push_back(arr[k][i]);
		k++;
		for(int i=k;i<x;i++)
			sorted.push_back(arr[i][n-1]);
		n--;
		
		if(k < x){
			for(int i=n-1;i>=l;i--)
				sorted.push_back(arr[x-1][i]);
			x--;
		}
		if(l < n){
			for(int i=x-1;i>=k;i--)
				sorted.push_back(arr[i][l]);
			l++;
		}
	}
	return sorted;
}

// main function
int main(){
	vector<vector<int>> arr = {{1,2,3},
		{8,9,4},
		{7,6,5}};
	vector<int> ans = snailSort(arr);
	for(int i : ans)
		cout << i << "\n";
    return 0;
}