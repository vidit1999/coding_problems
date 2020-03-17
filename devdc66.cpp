#include <bits/stdc++.h>
using namespace std;

/*
John has invited some friends. His list is:

s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";

Could you make a program that:
-makes this string uppercase
-gives it sorted in alphabetical order by last name

When the last names are the same, sort them by first name.
Last name and first name of a guest come in the result between parentheses separated by a comma.

So the result of function meeting(s) will be:

"(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)
(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"

It can happen that in two distinct families with the same family name two people have the same first name too.
*/

string specialSort(string s){
	string firstName = "";
	string lastName = "";
	vector<pair<string, string>> names;
	bool appendInFirst = true;
	for(int i=0;i<s.length();i++){
		if(s[i] == ':'){
			appendInFirst = false;
			continue;
		}
		else if(s[i] == ';'){
			appendInFirst = true;
			names.push_back(make_pair(lastName,firstName));
			lastName = "";
			firstName = "";
			continue;
		}
		if(appendInFirst)
			firstName += toupper(s[i]);
		else
			lastName += toupper(s[i]);
	}
	names.push_back(make_pair(lastName,firstName));
	// all the above code is used to make a vector of pair
	// first element of pair is last name and second element is first name
	
	// cpp sort already sorts a vector of pair the way we need here
	// so need to write custom comparator
	sort(names.begin(),names.end());
	
	string nameList = "";
	for(auto it : names){
		nameList += "("+it.first+", "+it.second+")";
	}
	return nameList;
}

// main function
int main(){
	cout << specialSort("Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill") << "\n";
	return 0;
}