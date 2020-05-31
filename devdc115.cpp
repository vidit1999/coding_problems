#include <bits/stdc++.h>
using namespace std;

/*
The look and say sequence is a sequence in which each number is the result of a "look and say"
operation on the previous element.

For example, starting with "1": ["1", "11", "21, "1211", "111221", ...]. You can see that the
second element describes the first as "1(times number)1", the third is "2(times number)1" describing
the second, the fourth is "1(times number)2(and)1(times number)1" and so on.

Your goal is to create a function which takes a starting string (not necessarily the classical "1")
and return the nth element of the series.

Examples:
lookAndSaySequence("1", 1) === "1"
lookAndSaySequence("1", 3) === "21"
lookAndSaySequence("1", 5) === "111221"
lookAndSaySequence("22", 10) === "22"
lookAndSaySequence("14", 2) === "1114"
*/

string genNextSeq(string s){
	if(s.length() == 1)
		return "1" + string(1,s[0]);
	
	string ans = "";
	int i, count = 1;
	for(i=1;i<s.length();i++){
		if(s[i] != s[i-1]){
			ans += to_string(count) + s[i-1];
			count = 1;
		}
		else
			count++;
	}
	
	ans += to_string(count) + s[i-1];
	return ans;
}

string lookAndSaySequence(string number, int count){
	if(count == 1)
		return number;
	
	return lookAndSaySequence(genNextSeq(number), count-1);
}

// main function
int main(){
	cout << lookAndSaySequence("1", 1) << "\n";
	cout << lookAndSaySequence("1", 3) << "\n";
	cout << lookAndSaySequence("1", 5) << "\n";
	cout << lookAndSaySequence("22", 10) << "\n";
	cout << lookAndSaySequence("14", 2) << "\n";
	return 0;
}