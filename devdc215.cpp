#include <bits/stdc++.h>
using namespace std;

/*
The objective is to implement a function that will return
all pairs of integers from a given array of integers that
have a difference of 2. The result array should be sorted in ascending order of values.

Assume there are no duplicate integers in the array.
The order of the integers in the input array should not matter.

Examples
[1, 2, 3, 4]      -->  [[1, 3], [2, 4]]
[4, 1, 2, 3]      -->  [[1, 3], [2, 4]]
[1, 23, 3, 4, 7]  -->  [[1, 3]]
[4, 3, 1, 5, 6]   -->  [[1, 3], [3, 5], [4, 6]]

Tests
pairDifference([1,2,3,4])
pairDifference([1,3,4,6])
*/

vector<pair<int, int>> pairDifference(vector<int> arr){
    // store all the numbers in a set for ease of searching
    // cpp set stores all numbers in ascending order by default
    set<int> numbers(arr.begin(), arr.end());

    // stores the pairs which have difference of two
    vector<pair<int, int>> numPairs;

    for(int num : numbers){
        // for any number num if num+2 is also in the set
        // then include it in the vector
        if(numbers.find(num+2) != numbers.end()){
            numPairs.push_back(make_pair(num,num+2));
        }
    }
    return numPairs;
}

// function for tesing purposes
void testFunc(vector<vector<int>> allArrays){
    for(auto v : allArrays){
        vector<pair<int, int>> ans = pairDifference(v);
        for(auto it : ans){
            cout << it.first << " -- " << it.second << "\n";
        }
        cout << "-----\n";
    }
}

// main function
int main(){
    testFunc({{1, 2, 3, 4},{4, 1, 2, 3},{1, 23, 3, 4, 7},{4, 3, 1, 5, 6},{1,3,4,6}});
    return 0;
}