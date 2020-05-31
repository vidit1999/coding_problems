#include <bits/stdc++.h>
using namespace std;

/*
The wide mouth frog is particularly interested in the eating habits of other creatures.

He just can't stop asking the creatures he encounters what they like to eat.
But then he meets the alligator who just LOVES to eat wide-mouthed frogs!

When he meets the alligator, it then makes a tiny mouth.

Your goal in this kata is to create complete the mouth_size method this method
takes one argument animal which corresponds to the animal encountered by the frog.
If this one is an alligator (case insensitive) return small otherwise return wide.
*/

string mouth_size(string animal){
    transform(animal.begin(), animal.end(), animal.begin(), ::tolower);
    return (animal == "alligator")? "small" : "wide";
}

// main function
int main(){
    cout << mouth_size("alligator") << "\n";
    cout << mouth_size("bunny") << "\n";
    cout << mouth_size("alligaTor") << "\n";
    
	return 0;
}