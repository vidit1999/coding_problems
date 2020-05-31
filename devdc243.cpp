#include <bits/stdc++.h>
using namespace std;

/*
The first document has parts redacted, and the other one doesn't.
But the clean document might be a fake!
You need to compare the two documents and decide if it is possible they are the same or not.
Return true if the two documents are possibly the same. Return false otherwise.

Rules

Each document is made of any visible characters, spaces, punctuation, and newlines \n
Any character might be redacted (except \n)
The redaction character is X
The redacted document is always the first one

Example
doc1 = "TOP SECRET:\nThe missile launch code for Sunday XXXXXXXXXX is:\nXXXXXXXXXXXXXXXXX"
doc2 = "TOP SECRET:\nThe missile launch code for Sunday 5th August is:\n7-ZERO-8X-ALPHA-1"
Documents look the same, therefore true.

Tests
doc1 = "The name of the mole is Professor XXXXX"
doc2 = "The name of the mole is Professor Dinglemouse"

doc1 = "XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\nXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX"
doc2 = "Area-51. Medical Report. 23/Oct/1969\nE.T. subject 4 was given an asprin after reporting sick for duty today"
*/

bool areSame(string doc1, string doc2){
	if(doc1.length() != doc2.length())
		return false;
	
	for(int i=0; i<doc1.length(); i++)
		if(doc1[i] != doc2[i] && (doc1[i] != 'X' || (doc1[i] == 'X' && doc2[i] == '\n')))
			return false;
	
	return true;
}

void testFunc(vector<string> v1, vector<string> v2){
	for(int i=0;i<v1.size();i++){
		if(areSame(v1[i], v2[i]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	vector<string> v1 = {
		"TOP SECRET:\nThe missile launch code for Sunday XXXXXXXXXX is:\nXXXXXXXXXXXXXXXXX",
		"The name of the mole is Professor XXXXX",
		"XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\nXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX"
	},
	
	v2 = {
		"TOP SECRET:\nThe missile launch code for Sunday 5th August is:\n7-ZERO-8X-ALPHA-1",
		"The name of the mole is Professor Dinglemouse",
		"Area-51. Medical Report. 23/Oct/1969\nE.T. subject 4 was given an asprin after reporting sick for duty today"
	};
	
	testFunc(v1, v2);
	return 0;
}