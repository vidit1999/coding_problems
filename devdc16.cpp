#include <bits/stdc++.h>
using namespace std;

/*
There is a bus moving in the city, and it takes and drop some people at each bus stop.
You are provided with a list (or array) of integer arrays (or tuples).
Each integer array has two items which represent the number of people
that get on the bus (The first item) and the number of people that get off the bus (The second item) at a bus stop.

Your task is to return number of people who are still left on the bus after the last bus station (after the last array).
*/

int peopleLeft(vector<pair<int, int>> passengers){
    int peopleLeft = 0;
    for_each(passengers.begin(),passengers.end(),[&](pair<int,int> p){peopleLeft += (p.first-p.second);});
    return peopleLeft;
}

// main function
int main(){
    cout << peopleLeft({{1, 0}, {2, 1}, {5, 3}, {4, 2}}) << "\n";
    return 0;
}