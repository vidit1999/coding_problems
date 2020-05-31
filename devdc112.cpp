#include <bits/stdc++.h>
using namespace std;

/*
Consider integer coordinates x, y in the Cartesian plane and three functions f, g, h defined by:

f: 1 <= x <= n, 1 <= y <= n --> f(x, y) = min(x, y)
g: 1 <= x <= n, 1 <= y <= n --> g(x, y) = max(x, y)
h: 1 <= x <= n, 1 <= y <= n --> h(x, y) = x + y
where n is a given integer (n >= 1, guaranteed) and x, y are integers.

In the table below you can see the value of f(n) where n = 6.


The challenge is to calculate the sum of f(x, y), g(x, y), and h(x, y) for all
integers x and y such that (1 <= x <= n, 1 <= y <= n)

The function sumin (sum of f) will take n as a parameter and return the sum of
min(x, y) in the domain 1 <= x <= n, 1 <= y <= n. The function sumax (sum of g)
will take n as a parameter and return the sum of max(x, y) in the same domain.
The function sumsum (sum of h) will take n as a parameter and return the sum of x + y in the same domain.

sumin(6) --> 91
sumin(45) --> 31395
sumin(999) --> 332833500
sumin(5000) --> 41679167500

sumax(6) --> 161
sumax(45) --> 61755
sumax(999) --> 665167500
sumax(5000) --> 83345832500

sumsum(6) --> 252
sumsum(45) --> 93150
sumsum(999) --> 998001000
sumsum(5000) --> 125025000000
*/

long long sumin(int n){
	return n*(n+1)*(2*n+1)/6;
}

long long sumax(int n){
	return n*(n+1)*(4*n-1)/6;
}

long sumsum(int n){
	return n*n*(n+1);
}

// main function
int main(){
	cout << sumin(6) << "\n";
    cout << sumin(45) << "\n";
    cout << sumin(999) << "\n";
    cout << sumin(5000) << "\n";
    cout << sumax(6) << "\n";
    cout << sumax(45) << "\n";
    cout << sumax(999) << "\n";
    cout << sumax(5000) << "\n";
    cout << sumsum(6) << "\n";
    cout << sumsum(45) << "\n";
    cout << sumsum(999) << "\n";
    cout << sumsum(5000) << "\n";
	return 0;
}