#include <bits/stdc++.h>
using namespace std;

/*
Implement a function pattern, which returns the following pattern for up to n number of rows.
If n < 1 then it should return " " i.e. empty string. There are no whitespaces in the pattern.

Pattern:
1
22
333
....
.....
nnnnnn

Examples
pattern(5):
1
22
333
4444
55555

pattern(11):
1
22
333
4444
55555
666666
7777777
88888888
999999999
10101010101010101010
1111111111111111111111

Tests
pattern(4)
pattern(8)
pattern(0.5)
*/

string pattern(int number){
    string pat = "";
    
    // there is no new-line at the end so loop end is number-1
    for(int i=1;i<=number-1;i++){
        for(int j=0;j<i;j++)
            pat += to_string(i); // add the string version of number
        pat += "\n"; // add a new-line after adding the numbers each time 
    }

    // add the case of number at the end with no new-line
    for(int i=0;i<number;i++)
        pat += to_string(number);
    
    return pat;
}

// main function
int main(){
    cout << pattern(1) << "\n";
    cout << pattern(11) << "\n";
    cout << pattern(5) << "\n";
    cout << pattern(4) << "\n";
    cout << pattern(0.5) << "\n";
    cout << pattern(8) << "\n";
    cout << pattern(0) << "\n";
    return 0;
}