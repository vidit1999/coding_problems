#include <bits/stdc++.h>
using namespace std;

/*
You are given two strings s and t.
Both strings have length n and consist of lowercase letters.

You can swap any two adjacent characters of s any number of times.
Output the minimum number of moves to transform s to t.
If it is impossible to obtain the string t using moves, return -1.

Examples
('abcdef', 'abfdec') => 4
('abcd', 'accd') => -1
('ab', 'ab') => 0
('ab', 'ba') => 1
('aaa', 'aaa') => 0

Tests
{s:'abcdef', t:'abdfec'}
{s:'abcd', t:'accd'}
{s:'ab', t:'ab'}
{s:'ab', t:'ba'}
{s:'aaa', t:'aaa'}
*/

int minimumNumberMoves(string s, string t){
    // check if all character of t is present in s or not in equal amount
    // it not return -1
    unordered_map<char, int> char_count;
    for(char c : t) char_count[c]++; // incease the count for chars of t
    for(char c : s) char_count[c]--; // decrase the count for char of s

    for(auto it : char_count){
        // if count of any char is not zero then return -1
        if(it.second != 0)
            return -1;
    }

    // now we know that s can be transformed to t
    int count = 0, n = s.length();

    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            // locate the index of t[i] in s[i+1 .. n-1]
      int j = i+1;
            for(;j<n;j++){
                if(s[j] == t[i])
                    break;
            }

            // start swapping the chars of s
            // bring the char of s[j] to s[i]
            for(int k=j;k>i;k--){
                swap(s[k], s[k-1]);
                count++;
            }
        }
    }

    return count;
}

// main function
int main(){
    vector<pair<string, string>> v = {
        {"abcdef", "abdfec"},
        {"abcd", "accd"},
        {"ab", "ab"},
        {"ab", "ba"},
        {"aaa", "aaa"},
    };

    for(auto it : v){
        cout << minimumNumberMoves(it.first, it.second) << "\n";
    }
    return 0;
}