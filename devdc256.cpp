#include <bits/stdc++.h>
using namespace std;

/*
Write function smaller(arr) that given an array arr, you have to return the amount of numbers
that are smaller to the right of that number in the index.

For example:
smaller([5, 4, 3, 2, 1]) === [4, 3, 2, 1, 0]
smaller([1, 2, 0]) === [1, 1, 0]

Tests:
smaller([5, 4, 3, 2, 1])
smaller([1, 2, 3])
smaller([1, 1, -1, 0, 0])
smaller([5, 4, 7, 9, 2, 4, 4, 5, 6])
*/

vector<int> smaller(vector<int> arr){
    map<int, int> m;
    vector<int> ans(arr.size(), 0);

    for(int i = arr.size()-1; i >= 0; i--){
        auto it = m.insert({arr[i], m[arr[i]]++});

        for(auto itr = m.begin(); itr != it.first; itr++) ans[i] += (*itr).second;
    }

    return ans;
}

void testFunc(vector<vector<int>> v){
    for(auto ans : v){
        for(int i : smaller(ans))
            cout << i << " ";
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {5, 4, 3, 2, 1},
        {1, 2, 0},
        {1, 2, 3},
        {1, 1, -1, 0, 0},
        {5, 4, 7, 9, 2, 4, 4, 5, 6}
    });
    return 0;
}