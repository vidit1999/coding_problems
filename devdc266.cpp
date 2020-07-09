#include <bits/stdc++.h>
using namespace std;

/*
You probably know the "like" system from Facebook and other pages.
People can "like" blog posts, pictures or other items.
We want to create the text that should be displayed next to such an item.

Implement a function likes :: [String] -> String, which must
take in input array, containing the names of people who like an item.
It must return the display text as shown in these examples:

likes {} // must be "no one likes this"
likes {"Peter"} // must be "Peter likes this"
likes {"Jacob", "Alex"} // must be "Jacob and Alex like this"
likes {"Max", "John", "Mark"} // must be "Max, John and Mark like this"
likes {"Alex", "Jacob", "Mark", "Max"} // must be "Alex, Jacob and 2 others like this"

For 4 or more names, the number in and 2 others simply increases.
*/

string whoLikes(vector<string> names){
	switch(names.size()){
		case 0:
			return "no one likes this";
		case 1:
			return names[0] + " likes this";
		case 2:
			return names[0] + " and " + names[1] + " like this";
		case 3:
			return names[0] + ", " + names[1] + " and " + names[2] + " like this";
	}

	return names[0] + ", " + names[1] + " and " + to_string(names.size() - 2) + " others like this";
}

void testFunc(vector<vector<string>> v){
	for(auto names : v){
		cout << whoLikes(names) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{},
		{"Peter"},
		{"Jacob", "Alex"},
		{"Max", "John", "Mark"},
		{"Alex", "Jacob", "Mark", "Max"}
	});
	return 0;
}