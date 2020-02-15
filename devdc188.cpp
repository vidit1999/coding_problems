#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will turn a camelCase word into a
regular one by adding spaces and lower-casing the words.

Examples
ccbreaker("camelCasing") == "camel casing"
ccbreaker("garbageTruck") == "garbage truck"

Tests
ccbreaker("policeSiren") == "police siren"
ccbreaker("camelCasingTest") =="camel casing test"
*/


string ccbreaker(string camelCased){
    string nonCamelCased = ""; // string that is ragular one
    for(char c : camelCased){
        // whenever a upper case letter is encountered first add a space
        // and then add its lower case version
        if(c <= 90 && c >= 65){
            nonCamelCased += " ";
            nonCamelCased += char(c+32);
        }
        // if not uppercase then simply add it
        else{
            nonCamelCased += c;
        }
    }
    return nonCamelCased;
}

// main function
int main(){
    cout << ccbreaker("camelCasing") << "\n";
    cout << ccbreaker("garbageTruck") << "\n";
    cout << ccbreaker("policeSiren") << "\n";
    cout << ccbreaker("camelCasingTest") << "\n";
    cout << ccbreaker("testing") << "\n";
    cout << ccbreaker("nonCamelCased") << "\n";
    return 0;
}