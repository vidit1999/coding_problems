#include <bits/stdc++.h>
using namespace std;

/*
Pirates are notoriously bad at pronunciation. For this challenge, implement a function that will
accept a jumbled word and a dictionary. It should output the words that the pirate might have been saying.

Example
grabscrab( "ortsp", ["sport","parrot","ports","matey"])
=> ["sport", "ports"]

Tests
grabscrab("trisf", ["first"])
grabscrab("oob", ["bob", "baobab"])
grabscrab("ainstuomn", ["mountains", "hills", "mesa"])
grabscrab("oolp", ["donkey", "pool", "horse", "loop"])
*/

// takes two words and checks if
// the second one has all the letters of first word
bool checkAllLetters(string word1, string word2){
    unordered_set<char> wordSet;
    for(char c : word2)
        wordSet.insert(c);
    for(char c : word1){
        if(wordSet.find(c)==wordSet.end())
            return false;
    }
    return true;
}


// takes the dictionary as a vector
// returns the possibe words as vector
vector<string> grabscrab(string word, vector<string> possibleWords){
    vector<string> posWords;
    for(string w : possibleWords){
        if(checkAllLetters(word, w))
            posWords.push_back(w);
    }
    return posWords;
}

// testing function
void testFunction(string jumbledWord, vector<string> possibleWords){
    vector<string> res = grabscrab(jumbledWord, possibleWords);
    if(res.size()==0){
        cout << "No possible words\n";
        return;
    }
    for(string s : res)
        cout << s << " ";
    cout << "\n";
}

// main function
int main(){
    testFunction("ortsp",vector<string>({"sport","parrot","ports","matey"}));
    testFunction("trisf",vector<string>({"first"}));
    testFunction("oob",vector<string>({"bob", "baobab"}));
    testFunction("ainstuomn",vector<string>({"mountains", "hills", "mesa"}));
    testFunction("oolp",vector<string>({"donkey", "pool", "horse", "loop"}));
    return 0;
}