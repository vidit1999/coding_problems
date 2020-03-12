#include <bits/stdc++.h>
using namespace std;

/*
Given a phone number of integer length N (1 ≤ N ≤ 10) as a
number string (e.g. 555-555-5555 would be passed as "5555555555"),
return an array of all phone numbers as number strings that would be
considered neighbors of that phone number (which is any numbers ±1).

For example: someone with the phone number 555-555-5555 has neighbors 555-555-5554 and 555-555-5556.
*/

long long powerOfTen(int n){
    long long res = 1;
    for(int i=1;i<=n;i++)
        res *= 10;
    return res;
}

vector<string> neighbourPhoneNumber(string phoneNumber){
    long long phNumber = stoll(phoneNumber);
    vector<string> neighbours;
    for(int i=0;i<10;i++){
        if(phNumber > 1000000000)
            neighbours.push_back(to_string(phNumber - powerOfTen(i)));
        if(phNumber < 9999999999)
            neighbours.push_back(to_string(phNumber + powerOfTen(i)));
    }
    return neighbours;
}

/*
f('5555555555').join('\n');
"5555555555
5555555554
5555555556
5555555545
5555555565
5555555455
5555555655
5555554555
5555556555
5555545555
5555565555
5555455555
5555655555
5554555555
5556555555
5545555555
5565555555
5455555555
5655555555
4555555555
6555555555"
*/

// main function
int main(){
    vector<string> neighbours = neighbourPhoneNumber("5555555555");
    for(string s : neighbours)
        cout << s << "\n";
    return 0;
}