#include <bits/stdc++.h>
using namespace std;

/*
SMS messages are limited to 160 characters. It tends to be irritating, especially when
freshly written message is 164 characters long. Implement a function to shorten the
message to 160 characters, starting from the end, by replacing spaces with camelCase, as much as necessary.

Example
Original Message:
No one expects the Spanish Inquisition! Our chief weapon is surprise, fear and surprise; two chief weapons, fear, surprise, and ruthless efficiency! And that will be it.

Shortened Message:
No one expects the Spanish Inquisition! Our chief weapon is surprise, fear and surprise; two chief weapons, fear,Surprise,AndRuthlessEfficiency!AndThatWillBeIt.

Tests
"SMS messages are limited to 160 characters. It tends to be irritating, especially when freshly written message is 164 characters long. SMS messages are limited to 160 characters. It tends to be irritating, especially when freshly written message is 164 characters long."

"This message is already short enough!"

"ThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoon"
*/

char toUpperCase(char c){
    if(c >= 97 && c <= 122)
        return char(c-32);
    return c;
}


// returned the shorteden message
string smsShortner(string sms){
    if(sms.length() <= 160)
        return sms;
    
    int spaceToReduce = sms.length()-160; // how many spaces we need to cut
    string shortened = "";
    int pos = sms.length()-1;

    while(pos > 0 && spaceToReduce > 0){
        if(sms[pos-1] != ' '){
            shortened = sms[pos] + shortened;
        }
        else{
            shortened = toUpperCase(sms[pos]) + shortened;
            spaceToReduce--;
            pos--;
        }
        pos--;
    }
    if(pos >= 0){
        for(int i=pos;i>=0;i--)
            shortened = sms[i] + shortened;
    }
    return shortened;
}

// test function
void testFunction(string sms){
    cout << smsShortner(sms) << "\n\n";
}

// main function
int main(){
    testFunction("No one expects the Spanish Inquisition! Our chief weapon is surprise, fear and surprise; two chief weapons, fear, surprise, and ruthless efficiency! And that will be it.");
    testFunction("SMS messages are limited to 160 characters. It tends to be irritating, especially when freshly written message is 164 characters long. SMS messages are limited to 160 characters. It tends to be irritating, especially when freshly written message is 164 characters long.");
    testFunction("This message is already short enough!");
    testFunction("ThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoonThereIsNoSpoon");
    
    return 0;
}