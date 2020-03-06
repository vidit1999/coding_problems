#include <bits/stdc++.h>
using namespace std;

/*
Your task is to implement a function that would take
the Morse code as input and return a decoded human-readable string.

For example:
decodeMorse('.... . -.-- .--- ..- -.. .')
should return "HEY JUDE"

C++/Go/JavaScript/PHP/Python/Ruby/TypeScript:MORSE_CODE['.--']
C#:MorseCode.Get(".--") (returns string)
Elixir:morse_codes variable
Elm:MorseCodes.get : Dict String String
Haskell:morseCodes ! ".--" (Codes are in a Map String String)
Java:MorseCode.get(".--")
Kotlin:MorseCode[".--"] ?: "" or MorseCode.getOrDefault(".--", "")
Rust:self.morse_code
Scala: morseCodes(".--")

NOTE: For coding purposes, you should use ASCII characters . and -, not Unicode characters.
*/

// helper function to build an unordered map of morse codes
string morseEncode(char x){ 
    switch (x){
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case '0':
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case ' ': // for case of space return space
            return " ";
    }
}

// returns the morse code map
// maps char to morse code
unordered_map<char, string> morseCodeMap(){
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    unordered_map<char, string> codes;
    for(char c : alphabets){
        codes[c] = morseEncode(c);
    }
    return codes;
}

// encode a normal string to morse codes
string encodeMorse(string s){
    string encoded = "";
    unordered_map<char, string> morseCodes = morseCodeMap();
    for(int i=0;i<s.length();i++){
        encoded += morseCodes[s[i]];
        if(i < s.length()-1 && s[i] != ' ')
            encoded += " ";
    }
    return encoded;
}

// split string wrtr single space and returns a vector
// Example : spiltString("HEY  THERE") => ["HEY"," ","THERE"] as there are two spaces in the line
vector<string> spiltString(string s){
    string splited = "";
    int start = 0;
    vector<string> splits;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            splits.push_back(splited);
            start = i+1;
            if(i+1 < s.length() && s[i+1] == ' ')
                splited = " ";
            else
                splited = "";
        }
        else{
            splited += s[i];
        }
    }
    if(splited.length() > 0){
        splits.push_back(splited);
    }
    return splits;
}


// decode a morse code string to normal string
string decodeMorse(string s){
    string decoded = "";
    
    // build the reverse unordered map from before
    // i.e. it maps morse codes to characters
    unordered_map<char, string> morseCodes = morseCodeMap();
    unordered_map<string, char> morseCodesToChar;
    for(auto it : morseCodes){
        morseCodesToChar[it.second] = it.first;
    }

    vector<string> splitedMorseString = spiltString(s);
    for(string morsed : splitedMorseString){
        decoded += morseCodesToChar[morsed];
    }
    return decoded;
}

// main function
int main(){
    cout << encodeMorse("HEY JUDE") << "\n";
    cout << decodeMorse(encodeMorse("HEY JUDE")) << "\n";
}