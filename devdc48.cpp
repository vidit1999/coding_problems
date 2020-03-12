#include <bits/stdc++.h>
using namespace std;

/*
Create a like system from Facebook; a text which displays the names of people who liked an item.

For example:

likes [] must be "no one likes this"
likes ["Peter"] must be "Peter likes this"
likes ["Jacob", "Alex"] must be "Jacob and Alex like this"
likes ["Max", "John", "Mark"] must be "Max, John and Mark like this"
likes ["Alex", "Jacob", "Mark", "Max"] must be "Alex, Jacob and 2 others like this"

Note: For 4 or more names, the number in and 2 others simply increases.
*/

string facebookLikes(vector<string> persons){
    switch(persons.size()){
        case 0:
            return "no one likes this";
        case 1:
            return persons[0] + " likes this";
        case 2:
            return persons[0] + " and " + persons[1] + " like this";
        case 3:
            return persons[0] + ", " + persons[1] + " and " + persons[2] + " like this";
        default:
            return persons[0] + ", " + persons[1] + " and " + to_string(persons.size()-2) + " others like this";
    }
}

// main function
int main(){
    cout << facebookLikes({}) << "\n";
    cout << facebookLikes({"Peter"}) << "\n";
    cout << facebookLikes({"Jacob", "Alex"}) << "\n";
    cout << facebookLikes({"Max", "John", "Mark"}) << "\n";
    cout << facebookLikes({"Alex", "Jacob", "Mark", "Max"}) << "\n";
    return 0;
}