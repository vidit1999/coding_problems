#include <bits/stdc++.h>
using namespace std;

/*
Alex just got a new hula hoop, he loves it but feels discouraged because his little brother is better than him

Write a program where Alex can input (n) how many times the hoop goes round
and it will return him an encouraging message :)

If Alex gets 10 or more hoops, return the string "Great, now move on to tricks".

If he doesn't get 10 hoops, return the string "Keep at it until you get it".
*/

string encouragingMessage(int n){
	return (n > 9)? "Great, now move on to tricks" : "Keep at it until you get it";
}

// main function
int main(){
	cout << encouragingMessage(11) << "\n";
	cout << encouragingMessage(7) << "\n";
	cout << encouragingMessage(10) << "\n";
	return 0;
}