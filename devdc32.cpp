#include <bits/stdc++.h>
using namespace std;

/*
write a function that encrypts phone numbers.
The method should hide the last six digits of each phone number.

Example 1 (Using US phone number)
IN: 201-680-0202 => OUT: 201-6XX-XXXX

You can also have the code check the validity of the phone number's format.

Example 2
IN: 145-201-680-0202 => OUT: false
*/

// check if a phne number is valid or not (US phone number)
// returns true if valid else false
bool checkValidity(string phNo){
    // NXX-NXX-XXXX
    // N=digits 2–9, X=digits 0–9
    regex phoneNumber("^[2-9]{1}[0-9]{2}-[2-9]{1}[0-9]{2}-[0-9]{4}$");
    return regex_match(phNo,phoneNumber);
}

string encryptPhoneNo(string phNo){
    if(!checkValidity(phNo))
        return "false";
    string encryptedPhNumber = "";
    for(int i=0;i<phNo.length();i++){
        if(i <= 4 || i == 7)
            encryptedPhNumber += phNo[i];
        else
            encryptedPhNumber += 'X';
    }
    return encryptedPhNumber;
}

// main function
int main(){
    cout << encryptPhoneNo("201-680-0202") << "\n";
    cout << encryptPhoneNo("145-201-680-0202") << "\n";
    return 0;
}