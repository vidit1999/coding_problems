#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that will hide the last six digits of each phone number.
Your function should be able to understand the separators for US numbers.
Phone numbers can be separated by spaces, periods, or hyphens.

Examples
Original: 201-680-0202
Encrypted: `201-6XX-XXXX

Tests
encryptNum("328 6587120")
encryptNum("212-420-0202")
encryptNum("211-458-7851")
*/

// takes phone number and returns encrypted number
string encryptNum(string phoneNumber){
    int digitCount = 0;
    string encryptedNumber = "";
    for(int i=phoneNumber.length()-1;i>=0;i--){
        if(phoneNumber[i] >= 48 && phoneNumber[i] <= 57){
            if(digitCount < 6){
                encryptedNumber = 'X' + encryptedNumber;
                digitCount++;
                continue;
            }
        }
        encryptedNumber = phoneNumber[i] + encryptedNumber;
    }
    return encryptedNumber;
}


// function for testing
void testFunction(string phoneNumber){
    cout << phoneNumber << " ===> " << encryptNum(phoneNumber) << "\n";
}

// main function
int main(){
    testFunction("201-680-0202");
    testFunction("328 6587120");
    testFunction("212-420-0202");
    testFunction("211-458-7851");
    return 0;
}