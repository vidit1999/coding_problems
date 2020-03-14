#include <bits/stdc++.h>
using namespace std;

/*
Given a lowercase string that has alphabetic characters only and no spaces, implement a function that will return the highest value of consonant substrings. Consonants are any letters of the alphabet except "aeiou".

We shall assign the following values: a = 1, b = 2, c = 3, .... z = 26.

For example, for the word "zodiacs", let's cross out the vowels. We get: "z, d, cs". The values are z = 26, d = 4 and cs = 3 + 19 = 22. The highest is 26.
solve("zodiacs") = 26

For the word "strength", solve("strength") = 57
-- The consonant substrings are: "str" and "ngth" with values "str" = 19 + 20 + 18 = 57 and "ngth" = 14 + 7 + 20 + 8 = 49. The highest is 57.

Tests
solve("chruschtschov") => 80
solve("khrushchev")
solve("strength")
solve("catchphrase")
solve("twelfthstreet")
solve("mischtschenkoana")
*/

int solve(string s){
    int tempMax = 0, maxSoFar = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            maxSoFar = max(tempMax, maxSoFar);
            tempMax = 0;
        }
        else{
            tempMax += s[i]-'a'+1;
        }
    }
    return max(maxSoFar, tempMax);
}

int main(){
    cout << solve("zodiac") << "\n";
    cout << solve("chruschtschov") << "\n";
    cout << solve("khrushchev") << "\n";
    cout << solve("strength") << "\n";
    cout << solve("catchphrase") << "\n";
    cout << solve("twelfthstreet") << "\n";
    cout << solve("mischtschenkoana") << "\n";
    cout << solve("box") << "\n";
    return 0;
}