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
pattern(4):
4321
432
43
4

pattern(11):
1110987654321
111098765432
11109876543
1110987654
111098765
11109876
1110987
111098
11109
1110
11
Tests
pattern(5)
pattern(8)
pattern(0.5)
*/

string pattern(int n){
    string pat = "";
    for(int i=1;i<n;i++){
        for(int j=n;j>=i;j--)
            pat += to_string(j);
        pat += "\n";
    }
    if(n > 0)
        pat += to_string(n);
    return pat;
}

// recursive approach
string patternRec(int n, int end=1){
    string res = "";
    for(int i=n;i>=end;i--)
        res += to_string(i);
    if(end >= n)
        return res;
    return res + '\n' + patternRec(n, end+1);
}

// main function
int main(){
    cout << pattern(4) << "\n";
    cout << pattern(11) << "\n";
    cout << pattern(0.5) << "\n";
    cout << pattern(5) << "\n";
    cout << pattern(1.5) << "\n";
    cout << "\n--------------\n";
    cout << patternRec(4) << "\n";
    cout << patternRec(11) << "\n";
    cout << patternRec(0.5) << "\n";
    cout << patternRec(5) << "\n";
    cout << patternRec(1.5) << "\n";
    return 0;
}