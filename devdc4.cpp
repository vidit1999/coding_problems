#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

You are given a small checkbook to balance that is given to you as a string.
Sometimes, this checkbook will be cluttered by non-alphanumeric characters.
The first line shows the original balance. Each other (not blank) line gives information:
check number, category, and check amount.
You need to clean the lines first, keeping only letters, digits, dots, and spaces.
Next, return the report as a string. On each line of the report, you have to add the new balance.
In the last two lines, return the total expenses and average expense. Round your results to two decimal places.

Example Checkbook

1000.00
125 Market 125.45
126 Hardware 34.95
127 Video 7.45
128 Book 14.32
129 Gasoline 16.10

Example Solution

Original_Balance: 1000.00
125 Market 125.45 Balance 874.55
126 Hardware 34.95 Balance 839.60
127 Video 7.45 Balance 832.15
128 Book 14.32 Balance 817.83
129 Gasoline 16.10 Balance 801.73
Total expense 198.27
Average expense 39.65

Challenge Checkbook

1233.00
125 Hardware;! 24.8?;
123 Flowers 93.5
127 Meat 120.90
120 Picture 34.00
124 Gasoline 11.00
123 Photos;! 71.4?;
122 Picture 93.5
132 Tires;! 19.00,?;
129 Stamps 13.6
129 Fruits{} 17.6
129 Market;! 128.00?;
121 Gasoline;! 13.6?;

*/


// strips both sides of a string
// returns the striped string
string strip(string s){
	int startPos = 0;
	int endPos = s.length()-1;
	bool striped = false;
	while(startPos < endPos){
		striped = true;
		if(s[startPos] == ' ' || s[startPos] == '\t'){
			startPos++;
			striped = false;
		}
		if(s[endPos]==' ' || s[endPos] == '\t'){
			endPos--;
			striped = false;
		}
		if(striped)
			return s.substr(startPos,endPos-startPos+1);
	}
	return s;
}


// strips the strings and then splits it based on spaces
// returns a vector of those splited objects
vector<string> getStringSplited(string s,int lineNo){
	string st = strip(s.substr(0, s.length()));
	if(lineNo == 1)
		return vector<string>({st});
	int spos = 0;
	int i = 0;
	vector<string> v;
	while(spos<st.length()){
		while(st[i] != ' ' && i!=st.length()){
			i++;
		}
		string k = st.substr(spos,i-spos);
		if(!k.empty()){
			v.push_back(k);
		}
		spos = i+1;
		i++;
	}
	return v;
}

// returns a string based on its type whether it
// can contain decimal point or not
string cleanString(string s, bool containDec, vector<char> checkChar){
	if(!containDec){
		checkChar.push_back('.');
	}
	string st = "";
	for(char c : s){
		bool isJunk = false;
		for(char ch : checkChar){
			if(ch == c){
				isJunk = true;
				break;
			}
		}
		if(!isJunk)
			st += c;
	}
	if(!containDec){
		checkChar.pop_back();
	}
	return st;
}


vector<char> charForChecking(){
	vector<char> v;
	for(int i=33; i<=47 && i!=46;i++)
		v.push_back(static_cast<char>(i));
	for(int i=58;i<=64;i++)
		v.push_back(static_cast<char>(i));
	for(int i=91;i<=96;i++)
		v.push_back(static_cast<char>(i));
	for(int i=123;i<=126;i++)
		v.push_back(static_cast<char>(i));
	return v;
}

// prints a check book from raw string given as check book
void checkBook(string s){
	int spos = 0;
	int lineNo = 1;
	float balance = 0;
	float orgBalance = balance;
	float expenses = 0;
	vector<char> checkChar = charForChecking();
	for(int i=0;i<s.length();i++){
		if(s[i]=='\n' || i==s.length()){
			if(lineNo==1){
				string notCleaned = getStringSplited(s.substr(spos,i-spos),lineNo)[0];
				balance = stof(cleanString(notCleaned, true, checkChar));
				printf("Original_Balance: %.2f\n",balance);
				orgBalance = balance;
				spos = i+1;
				i++;
			}
			else{
				vector<string> v = getStringSplited(s.substr(spos,i-spos),lineNo);
				string checkNumber = cleanString(v[0], false, checkChar);
				string category = cleanString(v[1], false, checkChar);
				string checkAmount = cleanString(v[2], true, checkChar);
				float spend = stof(checkAmount);
				expenses += spend;
				balance -= spend;
				printf("%s %s %s Balance %.2f\n",checkNumber.c_str(),category.c_str(),checkAmount.c_str(),balance);
				i++;
				spos = i;
			}
			lineNo++;
		}
	}
	printf("Total expense %.2f\n",expenses);
	printf("Average expense %.2f\n",expenses/(lineNo-2));
}

// main function
int main(){
	string k = R"(1233.00
125 Hardware;! 24.8?;
123 Flowers 93.5
127 Meat 120.90
120 Picture 34.00
124 Gasoline 11.00
123 Photos;! 71.4?;
122 Picture 93.5
132 Tires;! 19.00,?;
129 Stamps 13.6
129 Fruits{} 17.6
129 Market;! 128.00?;
121 Gasoline;! 13.6?;
)";
	checkBook(k);
	return 0;
}