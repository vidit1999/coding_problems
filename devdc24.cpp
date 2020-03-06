#include <bits/stdc++.h>
using namespace std;

/*
Given a number, return the shortest amount of steps it would take from 1 to land exactly on that number.

A step is defined as:

Adding 1 to the number: num += 1
Doubling the number: num *= 2
You will always start from the number 1 and you will have to return
the shortest count of steps it would take to land exactly on that number.

Examples:

num == 3 would return 2 steps:

1 -- +1 --> 2: 1 step
2 -- +1 --> 3: 2 steps

2 steps

num == 12 would return 4 steps:

1 -- +1 --> 2: 1 step
2 -- +1 --> 3: 2 steps
3 -- x2 --> 6: 3 steps
6 -- x2 --> 12: 4 steps

4 steps
*/

int shortestNumSteps(int number){
    int numSteps = 0;
    while(number > 1){
        if(number%2 == 0){
            number /= 2;
            numSteps++;
        }
        else{
            number = --number / 2;
            numSteps += 2;
        }
    }
    return numSteps;
}

// main function
int main(){
    cout << shortestNumSteps(1) << "\n";
    cout << shortestNumSteps(2) << "\n";
    cout << shortestNumSteps(12) << "\n";
    cout << shortestNumSteps(7) << "\n";
    cout << shortestNumSteps(20) << "\n";
    return 0;
}