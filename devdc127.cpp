#include <bits/stdc++.h>
using namespace std;

/*
Everyone has to use passwords. One can choose a password from poems, songs, movies names and so on.
Unfortunately, some passwords can be easily guessed from lists of common cultural references.
You can make your passwords stronger through different means, such as writing a function to do the following:

Rules:
Select some text in capital letters, optionally including digits and non alphabetic characters,
Shift each letter by a given number but the transformed letter must be a letter (circular shift),
Replace each digit by its complement to 9,
Keep such as non alphabetic and non digit characters,
Lowercase each letter in odd position, uppercase each letter in even position (the first character is in position 0),
reverse the whole result.

Example:

your text: "BORN IN 2015!", shift 1

1 + 2 + 3 -> "CPSO JO 7984!"

4 "CpSo jO 7984!"

5 "!4897 Oj oSpC"
*/

string generateBasicPass(){
	int len = rand()%11 + 10;
	vector<int> password(len);
	int specialChar[] = {35, 36, 37, 38, 64};
	
	for(int i=0;i<len/2;i++)
		password[i] = rand()%26 + 65;
	
	for(int i=len/2;i<3*len/4;i++)
		password[i] = specialChar[rand()%5];
	
	for(int i=3*len/4;i<len;i++)
		password[i] = rand()%10 + 48;
	
	for(int i=0;i<len;i++)
		swap(password[i],password[rand()%len]);
	
	return string(password.begin(), password.end());
}


string makePasswordFromText(){
	int shift = rand()%11 + 1;
	string shifted = "";
	int evenPos = true;
	for(char c : generateBasicPass()){
		if(isupper(c)){
			if(evenPos)
				shifted += (c - 'A' + shift)%26 + 'A';
			else
				shifted += tolower((c - 'A' + shift)%26 + 'A');
		}
		else if(isdigit(c))
			shifted += abs(c - '0' - 9) + '0';
		else
			shifted += c;
		
		evenPos = !evenPos;
	}
	
	reverse(shifted.begin(), shifted.end());
	return shifted;
	
}

// main function
int main(){
	srand(time(0));
	cout << makePasswordFromText() << "\n";
	cout << makePasswordFromText() << "\n";
	cout << makePasswordFromText() << "\n";
	cout << makePasswordFromText() << "\n";
	cout << makePasswordFromText() << "\n";
	return 0;
}