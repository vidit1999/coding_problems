#include <bits/stdc++.h>
using namespace std;

/*
Josephus and his forty men were trapped in a cave by the Romans.
Rather than reveal secrets or be captured, they opted for a mass suicide.
They gathered in a circle and killed one man every three. The man who survived was supposed to end his own life.

Your challenge for today is to write a function that will return the winning survivor of a Josephus permutation.
It should accept two parameters, the amount of people in total n, and the amount of steps between eliminations k.

For example, with n=7 and k=3 josephus_survivor(7,3) should act this way:

josephus_survivor(7,3) => means 7 people in a circle;
one every 3 is eliminated until one remains
[1,2,3,4,5,6,7] - initial sequence
[1,2,4,5,6,7] => 3 is counted out
[1,2,4,5,7] => 6 is counted out
[1,4,5,7] => 2 is counted out
[1,4,5] => 7 is counted out
[1,4] => 5 is counted out
[4] => 1 counted out, 4 is the last element - the survivor!

*/

int josephus_survivor(int n, int k){
    if(n==1)
        return 1;
    return (josephus_survivor(n-1,k)+k-1)%n + 1;
}

// main function
int main(){
    cout << josephus_survivor(7,3) << "\n";
    return 0;
}