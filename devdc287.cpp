#include <bits/stdc++.h>
using namespace std;

/*
For this challenge, forget everything you know about adding two large numbers together.
248+208=4416

Like in this photo, you'll be adding two numbers together without carrying numbers.
Write a function that will take two numbers as input and will add them together
without carrying. Write down every value you get.

Examples
2 + 11 = 13

16 + 18 = 214
1 + 1 = 2
6 + 8 = 14

122 + 81 = 1103
1 + 0 = 1
8 + 2 = 10
2 + 1 = 3

Tests
1222 + 30277
1236 + 30889
49999 + 49999
*/

// after converting to string
int addWithoutCarry(int num1, int num2){
	string s1 = to_string(num1), s2 = to_string(num2), ans;
	int n1 = s1.length()-1, n2 = s2.length()-1;

	while(n1>=0 && n2>=0){
		ans = to_string(s1[n1--] + s2[n2--] - 2*'0') + ans;
	}

	while(n1>=0){
		ans = s1[n1--] + ans;
	}

	while(n2>=0){
		ans = s2[n2--] + ans;
	}

	return stoi(ans);
}

// no conversion to string
int addWithoutCarry2(int num1, int num2){
    int ans = 0, p = 1;

    while(num1 || num2){
        int num = num1%10 + num2%10;
        ans += (num)*p;
        p *= 10;
        if(num >= 10) p *= 10;
        num1 /= 10;
        num2 /= 10;
    }

    return ans;
}

// main function
int main(){
	cout << addWithoutCarry(2 , 11) << "\n";
	cout << addWithoutCarry(16 , 18) << "\n";
	cout << addWithoutCarry(1 , 1) << "\n";
	cout << addWithoutCarry(6 , 8) << "\n";
	cout << addWithoutCarry(122 , 81) << "\n";
	cout << addWithoutCarry(1 , 0) << "\n";
	cout << addWithoutCarry(8 , 2) << "\n";
	cout << addWithoutCarry(2 , 1) << "\n";
	cout << addWithoutCarry(1222 , 30277) << "\n";
	cout << addWithoutCarry(1236 , 30889) << "\n";
	cout << addWithoutCarry(49999 , 49999) << "\n";
	
    cout << "\n";

    cout << addWithoutCarry2(2 , 11) << "\n";
	cout << addWithoutCarry2(16 , 18) << "\n";
	cout << addWithoutCarry2(1 , 1) << "\n";
	cout << addWithoutCarry2(6 , 8) << "\n";
	cout << addWithoutCarry2(122 , 81) << "\n";
	cout << addWithoutCarry2(1 , 0) << "\n";
	cout << addWithoutCarry2(8 , 2) << "\n";
	cout << addWithoutCarry2(2 , 1) << "\n";
	cout << addWithoutCarry2(1222 , 30277) << "\n";
	cout << addWithoutCarry2(1236 , 30889) << "\n";
	cout << addWithoutCarry2(49999 , 49999) << "\n";

	return 0;
}