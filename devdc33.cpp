#include <bits/stdc++.h>
using namespace std;

/*
From a given (or self-made) dictionary, write a function that will accept a
string and return the most similar string from the dictionary.
To complete this challenge, you'll have an entered term (lowercase string)
and an array of known words (also lowercase strings).
Your task is to find out which word from the dictionary is most similar
to the input term. Their similarity is defined by the minimum number of
letters that must be added, replaced, or removed to get from the entered
word to one of the dictionary words. The lower the number of required changes is,
the more similar the words are.

Words that are the same are obviously the most similar.
A word that needs one letter to be changed is more similar
to another word that needs 2 (or more) letters to be changed.

Use the arrays below, combine them, or make your own dictionaries.

Array 1 + Example
['cherry', 'pineapple', 'melon', 'strawberry', 'raspberry']
fruits.findMostSimilar('strawbery'); // must return "strawberry"
fruits.findMostSimilar('berry'); // must return "cherry"

Array 2
['stars', 'mars', 'wars', 'codec', 'codewars']

Array 3
['javascript', 'java', 'ruby', 'php', 'python', 'coffeescript']
*/

int LevenshteinDistance(string s1, int l1, string s2, int l2){
    if(l1 == 0)
        return l2;
    if(l2 == 0)
        return l1;
    int cost = (s1[l1-1] == s2[l2-1])? 0 : 1;
    return min(min(LevenshteinDistance(s1,l1-1,s2,l2)+1,LevenshteinDistance(s1,l1,s2,l2-1)+1),LevenshteinDistance(s1,l1-1,s2,l2-1)+cost);
}

string findMostSimilar(string word, vector<string> dict){
    int similarity = INT_MAX;
    string match = "";
    for(string s : dict){
        int lvDist = LevenshteinDistance(s,s.length(),word,word.length());
        if(lvDist < similarity){
            match = s;
            similarity = lvDist;
        }
    }
    return match;
}

// main function
int main(){
    vector<string> dict = {"cherry", "pineapple", "melon", "strawberry", "raspberry"};
    cout << findMostSimilar("strawbery",dict) << "\n";
    cout << findMostSimilar("berry",dict) << "\n";
    return 0;
}