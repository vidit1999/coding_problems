#include <bits/stdc++.h>
using namespace std;

/*
You are given two angles of a triangle in degrees.

Write a function to return the third angle. Only positive integers will be tested.

Sample Tests:
thirdAngle(30, 60)
thirdAngle(60, 60)
thirdAngle(43, 78)
thirdAngle(10, 20)
*/

float thirdAngle(float first, float second){
	return 180-first-second;
}

// main function
int main(){
	cout << thirdAngle(30, 60) << "\n";
	cout << thirdAngle(60, 60) << "\n";
	cout << thirdAngle(43, 78) << "\n";
	cout << thirdAngle(10, 20) << "\n";
	return 0;
}