#include <bits/stdc++.h>
using namespace std;

/*
A Caesar cipher, or a shift cipher, is one of the most well known encryption techniques.
It works by substituting the letters in the message with letters some fixed number of positions down the alphabet.

Your challenge is to write a function that will accept a string and a shift key.
It will return the encrypted text. If something in the string is not in the alphabet
(e.g. punctuation, spaces) leave it as is.

key: 1
plain: defend the east wall of the castle
cipher: efgfoe uif fbtu xbmm pg uif dbtumf

Bonus
Write a function that will crack the cipher without knowing the shift.
The shift key can only be in range of [1, 26].

key: 3
cipher: dwwdfn iurp wkh zrrgv dw gdzq
plain: attack from the woods at dawn

I've used the brute-force method before (printing every possible key and manually searching for the right one).
I can't wait to see other solutions to cracking this easy cipher.
*/

string encrypt(string plain, int key){
    string cipher;
    for(char c : plain){
        if(c >= 'A' && c <= 'Z'){ 
            cipher += (((c-'A'+ key) % 26)+ 'A');
        }
		else if(c >= 'a' && c <= 'z'){
			cipher += (((c-'a'+ key) % 26)+ 'a');
		}
        else{
            cipher += c;
        }
    }
	return cipher;
}

string decrypt(string encrypted, int key){
	return encrypt(encrypted, 26-key);
}

// main function
int main(){
	cout << encrypt("defend the east wall of the castle", 1) << "\n";
	cout << decrypt(encrypt("defend the east wall of the castle", 1), 1) << "\n";
    return 0;
}