#include <bits/stdc++.h>
using namespace std;

/*
A boy is walking home from school. To make the walk more enjoyable,
he decides to add up the numbers of the houses he passes during his walk.
Unfortunately, the numbers won't appear to him in any specific order, since he's regularly taking turns.

At some point during the walk, the boy encounters a house marked number 0.
This surprises him so much that he stops adding the numbers after that house to the total.

For the given array of house numbers, determine the sum that the boy will get.
There will always be at least one number 0 house on the path.

Examples
inputArray = [5, 1, 2, 3, 0, 1, 5, 0, 2] => 11

inputArray = [1, 4, 34, 124, 2, 0, 14, 51] => 165

Tests
inputArray = [5, 1, 2, 3, 0, 1, 5, 0, 2]

inputArray = [4, 2, 1, 6, 0]

inputArray = [4, 1, 2, 3, 0, 10, 2]

*/

int sumHouse(vector<int> numbers){
    int sum = 0;
    for(int i: numbers){
        if(i==0)
            return sum;
        sum += i;
    }
}

// main function
int main(){
    cout << sumHouse({5, 1, 2, 3, 0, 1, 5, 0, 2}) << "\n";
    cout << sumHouse({1, 4, 34, 124, 2, 0, 14, 51}) << "\n";
    cout << sumHouse({4, 2, 1, 6, 0}) << "\n";
    cout << sumHouse({4, 1, 2, 3, 0, 10, 2}) << "\n";
    cout << sumHouse({0, 4, 1, 2, 3, 0, 10, 2}) << "\n";
    return 0;
}