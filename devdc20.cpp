#include <bits/stdc++.h>
using namespace std;

/*
Create a function which checks a number for three different properties.

Is the number prime?
Is the number even?
Is the number a multiple of 10?

Each should return either true or false, which should be given as an array.
*/


vector<bool> checkNum(int number){
    // considering 0 is multiple of all numbers

    // if number is divisible by 10 return false, true, true
    if(number%10 == 0){
        return {false, true, true};
    }

    // number is not divisible by 10
    // if number is divisible by 2 return true, true, false if number == 2
    // else return false, true, false
    if(number%2 == 0){
        return {(number==2)? true : false , true, false};
    }

    // number is a odd number

    // if number == 1 return false, false, false
    if(number == 1)
        return {false, false, false};
    
    // primality test
    // as we know number is odd, i is incremented by 2
    for(int i=3;i*i<=number;i+=2)
        if(number%i == 0)
            return {false, false, false};
    return {true, false, false};
}

// function for testing 
void testFunc(int number){
    while(number--){
        cout << number << " -- ";
        vector<bool> v = checkNum(number);
        for(bool b : v){
            if(b)
                cout << "true ";
            else
                cout << "false ";
        }
        cout << "\n";
    }
}

// main function
int main(){
    testFunc(50);
    return 0;
}