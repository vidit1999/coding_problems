#include <bits/stdc++.h>
using namespace std;

/*
Remember back to your time in the schoolyard when girls would take a flower and tear its petals,
saying each of the following phrases each time a petal was torn:

I love you
a little
a lot
passionately
madly
not at all
When the last petal was torn there were cries of excitement, dreams, surging thoughts, and emotions.

Your goal in this kata is to determine which phrase the girls would say
for a flower of a given number of petals, where nb_petals > 0.
*/

vector<string> phrases = {
	"not at all",
    "I love you",
    "a little",
    "a lot",
    "passionately",
    "madly"
};

string phrase(int nb_petals){
	return phrases[nb_petals%6];
}

// main function
int main(){
	cout << phrase(3) << "\n";
	return 0;
}