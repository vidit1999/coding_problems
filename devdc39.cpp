#include <bits/stdc++.h>
using namespace std;

/*
You've just finished writing the last chapter for your novel when a virus suddenly infects your document.
It has swapped the 'i's and 'e's in 'ei' words and capitalized random letters.
In today's challenge, you will write a function which will:

a) remove the spelling errors in 'ei' words. (Example of 'ei' words: their, caffeine, deceive, weight)
b) only capitalise the first letter of each sentence. Make sure the rest of the sentence is in lower case.

Example: He haD iEght ShOTs of CAffIEne. => He had eight shots of caffeine.
Example: He haD iEght ShOTs of CAffIEne. thEn hE dIeD. => He had eight shots of caffeine. Then he died.
*/

string antiVirus(string s){
    string virusFree = "";
    bool firstWord = true;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            virusFree += s[i];
            continue;
        }
        if(firstWord){
            if(i < s.length()-1 && (s[i] == 'i' || s[i] == 'I') && (s[i+1] == 'e' || s[i+1] == 'E')){
                virusFree += toupper(s[i+1]);
                virusFree += tolower(s[i]);
                i++;
            }
            else{
                virusFree += toupper(s[i]);
            }
            firstWord = false;
        }
        else{
            if(i < s.length()-1 && (s[i] == 'i' || s[i] == 'I') && (s[i+1] == 'e' || s[i+1] == 'E')){
                virusFree += tolower(s[i+1]);
                virusFree += tolower(s[i]);
                i++;
            }
            else{
                virusFree += tolower(s[i]);
            }
            if(s[i] == '.')
                firstWord = true;
        }
    }
    return virusFree;
}

// main function
int main(){
    cout << antiVirus("He haD iEght ShOTs of CAffIEne.") << "\n";
    cout << antiVirus("He haD iEght ShOTs of CAffIEne. aFter thaT HE WenT tO SleeP.") << "\n";
    return 0;
}