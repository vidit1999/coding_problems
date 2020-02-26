#include <bits/stdc++.h>
using namespace std;

/*
Turn a given number (an integer > 0, < 1000) into the equivalent English words.
For example:

wordify(1) == "one"
wordify(12) == "twelve"
wordify(17) == "seventeen"
wordify(56) == "fifty six"
wordify(90) == "ninety"
wordify(326) == "three hundred twenty six"
*/

// handles the case of 1 single digit
string oneify(int num){
    switch (num){
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        
        default:
            return "";
    }
}

// handles the case when number is greater than 9 and less than 100
// one second digit is handled
string tenify(int num){
    if(num < 20){
        switch (num){
            case 10:
                return "ten";
            case 11:
                return "eleven";
            case 12:
                return "twelve";
            case 13:
                return "thirteen";
            case 14:
                return "fourteen";
            case 15:
                return "fifteen";
            case 16:
                return "sixteen";
            case 17:
                return "seventeen";
            case 18:
                return "eighteen";
            case 19:
                return "nineteen";
        }
    }
    int secondDigit = num/10;
    switch (secondDigit){
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "fourty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
    }
    return "";
}

// handles the case of 3rd digit
string hundredify(int num){
    int thirdDigit = num / 100;
    if(thirdDigit == 0)
        return "";
    return oneify(thirdDigit) + " hundread";
}

string wordify(int num){
    string wordified = "";
    if(num > 99){
        wordified += hundredify(num);
        num %= 100;
        if(num > 0)
            wordified += " ";
    }
    if(num > 9){
        wordified += tenify(num);
        if(num < 20)
            return wordified;
        
        num %= 10;
        if(num > 0)
            wordified += " ";
    }
    wordified += oneify(num);
    return wordified;
}

// prints all worified numbers from 1 to num
void testify(int num){
    for(int i=1;i<=num;i++){
        cout << wordify(i) << "\n";
    }
}

// main function
int main(){
    testify(329);
    return 0;
}