#include <bits/stdc++.h>
using namespace std;

/*
I'm not sure how many of you are familiar with the ancient rice and chessboard problem
(Wikipedia calls it wheat for some reason) but here's a quick recap for you: a young person asks,
as compensation, only 1 grain of rice for the first square, 2 grains for the second, 4 for the third,
8 for the fourth and so on, always doubling the previous.

Your task is pretty straightforward: Write a function that, given an amount of grain,
calculates to which square one needs to land on to reach at least that amount of grain.

As usual, a few examples might be way better than thousands of words from me:
squaresNeeded(grain) === chessboard square
squaresNeeded(0) === 0
squaresNeeded(1) === 1
squaresNeeded(2) === 2
squaresNeeded(3) === 2
squaresNeeded(31) === 5

Input is always going to be valid/reasonable: a non negative number.

Test Cases:
squaresNeeded(128) === ?
squaresNeeded(4000000) === ?
squaresNeeded(32768) === ?
*/

int squaresNeeded(int n){
    return ceil(log2(n+1));
}

// main function
int main(){
    cout << squaresNeeded(0) << "\n";
    cout << squaresNeeded(1) << "\n";
    cout << squaresNeeded(2) << "\n";
    cout << squaresNeeded(3) << "\n";
    cout << squaresNeeded(31) << "\n";
    cout << squaresNeeded(128) << "\n";
    cout << squaresNeeded(4000000) << "\n";
    cout << squaresNeeded(32768) << "\n";
	return 0;
}