#include <bits/stdc++.h>
using namespace std;

/*
If you're old enough, you might remember owning a flip phone, and sending your first text message with excitement in your eyes. Maybe you still have one lying in a drawer somewhere.
Let's try to remember the good old days and what it was like to send text messages with these devices. A lot of them had different layouts, most notably for special characters and spaces, so for simplicity we'll be using a fictional model with 3x4 key layout shown below:
-------------------------
|   1   |   2   |   3   |  <-- hold a key to type a number
|  .,?! |  abc  |  def  |  <-- press a key to type a letter
-------------------------
|   4   |   5   |   6   |  <-- Top row
|  ghi  |  jkl  |  mno  |  <-- Bottom row
-------------------------
|   7   |   8   |   9   |
|  pqrs |  tuv  |  wxyz |
-------------------------
|   *   |   0   |   #   |  <-- hold for *, 0 or #
|  '-+= | space |  case |  <-- press # to switch between upper/lower case
-------------------------
You'll receive a message and your job is to figure out which keys you need to press to output the given message with the lowest number of clicks possible. Return the result as a string of key inputs from top row (refer to diagram above).

Output string contains inputs that are shown at the top row of a key's layout (0-9*#), To type letters, press a button repeatedly to cycle through the possible characters. Pressing is represented by key's top row element repeated n times, where n is the position of character on that particular key. Examples:
2 => 'a', 9999 => 'z', 111 => '?', *** => '+'

To type numbers 0-9 and special characters *# - hold that key. Holding is represented by a number, followed by a dash. Examples:
3- => '3', 5-5-5- => '555'

Initially the case is lowercase. To toggle between lowercase and uppercase letters, use the # symbol. Case switching should only be considered when next character is alphabetic (a-z). Examples:
#2#9999 => 'Az' (remember, it's a toggle)
27-#2255 => 'a7BK' (do not switch before '7')

If you have 2 or more characters in a sequence that reside on the same button (refer to layout, bottom row), you have to wait before pressing the same button again. Waiting is represented by adding a space between 2 (or more) such characters. Example:
44 444 44 444 => 'hihi'

No need to wait after holding any key, even if next character resides on same button (4-4 => '4g'), or if there's a case switch between 2 characters on same button (#5#55 => 'Jk').

All inputs will be valid strings and only consist of characters from the key layout table.

Example
To put it all together, let's go over an example. Say you want to type this message - 'Def Con 1!':

Switch to uppercase with # and press 3 (#3 => D) (input is now in uppercase mode)
Switch to lowercase and press 3 twice (#33 => e). (Note that there is no waiting because of case switching)
Next character f is on button 3 again, and has the same case (lowercase input and lowercase character), so you have to wait to type again (' 333' => f).
In a similar manner type the second word (space is located on number 0). 0#222#666 660 => ' Con '
Finish off by holding 1 as 1- and typing ! as 1111 ('1-1111' = 1!). Note that after holding a key you don't need to wait to press another key.

Result:
sendMessage("Def Con 1!") => "#3#33 3330#222#666 6601-1111"

Tests
sendMessage("hey")
sendMessage("one two three")
sendMessage("Hello World!")
*/

// returns key bindings for characters as a unordered_map
// Example :
// = ----> ****
// l ----> 555
// - ----> **
// # ----> #-
// . ----> 1
// c ----> 222
// 4 ----> 4-
// etc.
unordered_map<char, string> keyBingings(){
    // all options are in this vector of string
    // last empty string is for character '#'
    vector<string> allOptions = {".,?!","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","'-+="," ",""};

    // make the key bindings for the keys
    unordered_map<char, vector<char>> keyOptions;
    for(int i=0;i<9;i++){
        keyOptions['0'+i+1] = vector<char>(allOptions[i].begin(), allOptions[i].end());
    }
    keyOptions['*'] = vector<char>(allOptions[9].begin(), allOptions[9].end());
    keyOptions['0'] = vector<char>(allOptions[10].begin(), allOptions[10].end());
    keyOptions['#'] = vector<char>(allOptions[11].begin(), allOptions[11].end());

    // this unordered_map maps a character to its key-typing
    // like 'a' -> "2", 'b' -> "22" etc.
    unordered_map<char, string> keyTypings;
    for(auto option : keyOptions){
        for(int i=0;i<option.second.size();i++){
            keyTypings[option.second[i]] = string(i+1,option.first);
        }
        // Add options for numbers like '2' -> "2-", '4' -> "4-"
        keyTypings[option.first] = option.first;
        keyTypings[option.first] += "-";
    }
    return keyTypings;
}


string sendMessage(string message){
    // get the key bindings for characters
    unordered_map<char, string> kb = keyBingings();
    // whether the word is upper case or not, true for upper case
    bool capital = false;
    string res = ""; // answer string

    for(int i=0;i<message.length();i++){
        // if the letter is lower case and capital is true
        // or letter is upper case and capital is false
        // then add a "#" and inverse the capital true to false or false to true
        if((islower(message[i]) && capital) || (isupper(message[i]) && !capital)){
            res += "#";
            capital = !capital;
        }

        // if same character is repeating then add a space
        // like for the case "hi" -> "44 444"
        if(!res.empty() && res[res.length()-1] == kb[tolower(message[i])][0])
            res += " ";
        
        // add the keybinging for the character's lower case
        res += kb[tolower(message[i])];
    }
    return res;
}

// main function
int main(){
    cout << sendMessage("Def Con 1!") << "\n"; // output -> #3#33 3330#222#666 6601-1111
    cout << sendMessage("hey") << "\n"; // output -> 4433999
    cout << sendMessage("one two three") << "\n"; // output -> 666 6633089666084477733 33
    cout << sendMessage("Hello World!") << "\n"; // output -> #44#33555 5556660#9#66677755531111

    return 0;
}