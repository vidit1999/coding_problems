#include <bits/stdc++.h>
using namespace std;

/*
Create a function called that accepts 2 string arguments and returns an
integer of the count of occurrences the 2nd argument is found in the first one.

If no occurrences can be found, a count of 0 should be returned.
The first argument can be an empty string. The second string argument must be of at least length 1.

Examples
strCount('Hello', 'o') // => 1
strCount('Hello', 'l') // => 2
strCount('', 'z') // => 0

Tests
strCount('oh goodness gracious', 'o')
strCount('howdy, pardner', 'd')
strCount('Incumbent President', 'e')
*/

int strCount(string str1, string str2){
    // if str1 or str2 is empty the n return 0
    if(str2.empty() || str1.empty())
        return 0;
    
    int count = 0; // stores the count of occurrences
    size_t start = 0; // position to start searching

    while((start =str1.find(str2,start)) != string::npos){
        count++;
        start += str2.length();
    }
    return count;
}

// main function
int main(){
    cout << strCount("Hello", "o") << "\n";
    cout << strCount("Hello", "l") << "\n";
    cout << strCount("", "z") << "\n";
    cout << strCount("oh goodness gracious", "o") << "\n";
    cout << strCount("howdy, pardner" , "d") << "\n";
    cout << strCount("Incumbent President" , "e") << "\n";
    return 0;
}