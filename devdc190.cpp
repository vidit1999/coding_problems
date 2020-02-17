#include <bits/stdc++.h>
using namespace std;

/*
For this challenge, you will have to write a function called capitalizeFirstLast
or capitalize_first_last. This function will capitalize the first and last letter
of each word, and lowercase what is in between.
capitalizeFirstLast "and still i rise" -- "AnD StilL I RisE"

Rules:
The function will take a single parameter, which will be a string.
The string can contain words separated by a single space.
Words are made of letters from the ASCII range only.
The function should return a string.
Only the first and last letters are uppercased.
All the other letters should be lowercased.

Examples:
capitalizeFirstLast "and still i rise"               -- "AnD StilL I RisE"
capitalizeFirstLast "when words fail music speaks"   -- "WheN WordS FaiL MusiC SpeakS"
capitalizeFirstLast "WHAT WE THINK WE BECOME"        -- "WhaT WE ThinK WE BecomE"
capitalizeFirstLast "dIe wITh mEMORIEs nOt dREAMs"   -- "DiE WitH MemorieS NoT DreamS"
capitalizeFirstLast "hello"                          -- "HellO"
*/

string capitalizeFirstLast(string s){
    string modifiedString = "";
    for(int i=0;i<s.length();i++){
        if(i==0 || (i>0 && s[i-1]==' ') || (i<s.length()-1 && s[i+1] == ' ') || i==s.length()-1){
           modifiedString += char(toupper(s[i]));
        }
        else{
            modifiedString += char(tolower(s[i]));
        }
    }
    return modifiedString;
}

int main(){
    cout << capitalizeFirstLast("and still i rise") << "\n";
    cout << capitalizeFirstLast("when words fail music speaks") << "\n";
    cout << capitalizeFirstLast("WHAT WE THINK WE BECOME") << "\n";
    cout << capitalizeFirstLast("dIe wITh mEMORIEs nOt dREAMs") << "\n";
    cout << capitalizeFirstLast("hello") << "\n";
    cout << capitalizeFirstLast("") << "\n";
    cout << capitalizeFirstLast("i") << "\n";
    cout << capitalizeFirstLast("ii") << "\n";
    cout << capitalizeFirstLast("iii") << "\n";
    return 0;
}