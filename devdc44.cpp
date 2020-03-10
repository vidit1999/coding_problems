#include <bits/stdc++.h>
using namespace std;

/*
The wave (known as the Mexican wave in the English-speaking world outside North America)
is an example of metachronal rhythm typically achieved in a packed stadium.
Spectators will start a cheer in one corner and then roll it around the arena,
with each section rising from its seat as it yells.

Today's challenge is to write a function that turns a string into a Mexican Wave.
You will be passed a string and you must return that string in an array where
an uppercase letter is a person standing up. The input string will always start lower-case.
If the character in the string is whitespace then pass over it.

Ex.
wave("hello") => []string{"Hello", "hEllo", "heLlo", "helLo", "hellO"}
*/

// we are modifying waves vector
void wave(string s, int pos, vector<string>& waves){
	
	if(pos >= s.length())
		return;
	string waveTemp = ""; // stores the wave if pos-th item is uppercased
	for(int i=0;i<s.length();i++){
		if(i == pos)
			waveTemp += toupper(s[i]);
		else
			waveTemp += s[i];
	}
	
	// push the temp wave into the vector
	waves.push_back(waveTemp);
	wave(s, pos + 1, waves); // recur with pos as pos+1
}

// main function
int main(){
	vector<string> waves;
	wave("hello", 0, waves);
	for(string s : waves)
		cout << s << "\n";
	return 0;
}