#include <bits/stdc++.h>
using namespace std;

/*
Americans can be weird sometimes. The first floor of a
building is typically referred to as the ground floor.
In some American buildings, there is no 13th floor because of old superstitions.

Implement a function that takes an American floor passed as an
integer and returns the actual floor number.
Your function should also work for basement floors.

Examples
getRealFloor(1) == 0
getRealFloor(0) == 0
getRealFloor(5) == 4
getRealFloor(15) == 13
getRealFloor(-3) == -3

Tests
getRealFloor(3)
getRealFloor(7)
getRealFloor(20)
getRealFloor(1)
getRealFloor(-6)
*/


int getRealFloor(int americanFloor){
    // there is no 13th floor because of old superstitions, so no case of 13 and -13 is considered
    return (americanFloor<1) ? (americanFloor>=-12) ? americanFloor : americanFloor+1 : (americanFloor<=12) ? americanFloor-1 : americanFloor-2;
}


// main function
int main(){
    cout << getRealFloor(1) << "\n";
    cout << getRealFloor(0) << "\n";
    cout << getRealFloor(5) << "\n";
    cout << getRealFloor(15) << "\n";
    cout << getRealFloor(-3) << "\n";
    cout << getRealFloor(3) << "\n";
    cout << getRealFloor(7) << "\n";
    cout << getRealFloor(20) << "\n";
    cout << getRealFloor(1) << "\n";
    cout << getRealFloor(-6) << "\n";
    cout << getRealFloor(-12) << "\n";
    cout << getRealFloor(-11) << "\n";
    cout << getRealFloor(-14) << "\n";
    return 0;
}