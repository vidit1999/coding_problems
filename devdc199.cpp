#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that will construct a list containing every positive rational number:

Build a binary tree where each node is a rational and the root is 1/1,
with the following rules for creating the nodes below:

The value of the left-hand node below a/b is a/a+b
The value of the right-hand node below a/b is a+b/b
So the tree will look like this:

                       1/1
                  /           \ 
            1/2                  2/1
           /    \              /     \
       1/3        3/2        2/3       3/1
      /   \      /   \      /   \     /   \
   1/4    4/3  3/5   5/2  2/5   5/3  3/4   4/1
Now traverse the tree, breadth first, to get a list of rationals.

[ 1/1, 1/2, 2/1, 1/3, 3/2, 2/3, 3/1, 1/4, 4/3, 3/5, 5/2, .. ]
Every positive rational will occur, in its reduced form, exactly once in the list, at a finite index.

We will use tuples of type [ Number, Number ] to represent rationals, where [a,b] represents a / b

Use this method to create an infinite list of tuples:
function* allRationals() => [Number,Number] // forever
matching the list described above:

allRationals => [ [1,1], [1,2], [2,1], [1,3], [3,2], .. ]

Tests
a = { 0: [1,1], 3: [1,3], 4: [3,2], 10: [5,2] }

a = { 100: [19,12], 1000: [39,28], 10000: [205,162], 100000: [713,586] }
*/

// returns the pos-th element in the allRationals list as a pair
// like allRationals(0) = [1,1], allRationals(10) = [5,2]
pair<int, int> allRationals(int pos){
    queue<pair<int,int>> rationals; // for storing like BFS
    rationals.push(make_pair(1,1)); // push the first pair
    int index = 0; // index of element in BFS array

    while(true){
        pair<int, int> p = rationals.front();
        if(index++ == pos)
            return p;
        rationals.pop();
        rationals.push(make_pair(p.first, p.first+p.second)); // push the left child [a,a+b]
        rationals.push(make_pair(p.first+p.second,p.second)); // push the right child [a+b,b]
    }
}

// if the rationals-list is required upto index pos, then this function can be used
// same as allRationals, but we are also storing elements in the vector while popping
// Example: rationals(4) = [[1,1], [1,2], [2,1], [1,3], [3,2]]
vector<pair<int,int>> rationals(int pos){
    queue<pair<int,int>> rationals; // for storing like BFS
    rationals.push(make_pair(1,1)); // push the first pair
    vector<pair<int,int> > rationalsArray;
    int index = 0; // index of element in BFS array

    while(true){
        pair<int, int> p = rationals.front();
        rationalsArray.push_back(p);
        if(index++ == pos)
            return rationalsArray;
        rationals.pop();
        rationals.push(make_pair(p.first, p.first+p.second)); // push the left child [a,a+b]
        rationals.push(make_pair(p.first+p.second,p.second)); // push the right child [a+b,b]
    }
}

// main function
int main(){
    vector<pair<int,int>> v = rationals(4);
    for(auto i : v){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}