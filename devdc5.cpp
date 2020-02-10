#include <bits/stdc++.h>
using namespace std;

/*

You live in a city where all roads are laid out in a perfect grid.
You have the unfortunate habit of arriving too early or too late to your appointments,
so you decide to create a Walk Generating App. Any time you press the button,
it will send you an array of one-letter strings representing directions to walk (eg. [‘n’,’s’,’w’,’e’]).
You always walk only a single block in a direction. It takes one minute to traverse one city block.
Create a program that will return an array of one-letter strings representing the walk.
The program should accept input for the amount of time the user decides to walk and
should bring the user back to their starting location.

Assuming :
1 step towards each direction takes 1 unit time

*/


vector<char> directions(int t){
	if(t%2 != 0){
		cout << "Not possible to return back\n";
		return vector<char>();
	}
	srand(time(0));
	vector<char> v;
	int nsCount = rand()%(t/2);
	int ewCount = (t/2) - nsCount;
	for(int i=0;i<nsCount;i++){
		v.push_back('n');
		v.push_back('s');
	}
	for(int i=0;i<ewCount;i++){
		v.push_back('e');
		v.push_back('w');
	}
	
	for(int i=0;i<v.size();i++){
		swap(v[i],v[rand()%(v.size())]);
	}
	
	return v;
}

// main function
int main(){
	vector<char> v = directions(14);
	for(char c : v)
		cout << c << " ";
	cout << "\n";
	return 0;
}