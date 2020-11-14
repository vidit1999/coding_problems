#include <bits/stdc++.h>
using namespace std;

/*
In Spanish, verbs change according to the person we're talking about.
Something similar happens in English when we use the third person singular pronouns he/she:

I run
You run
He/She runs

Spanish is similar, the suffix changes depending on who
we're talking about. Your task is to write a function
called conjugate which will return a Spanish verb in
all of its conjugations.

Examples
conjugate(comer)
["como", "comes", "come", "comemos", "coméis", "comen"]

conjugate(vivir)
["vivo", "vives", "vive", "vivimos", "vivís", "viven"]
*/

vector<string> conjugate(string s){
	if(s.length() < 2) return {};

	unordered_map<string, vector<string>> conjugation_map = {
		{"ar", {"o","as","a","amos","ais","an"}},
		{"er", {"o","es","e","emos","eis","en"}},
		{"ir", {"o","es","e","imos","is","en"}}
	};

	string first_portion = s.substr(0,s.length()-2);
	string last_two = s.substr(s.length()-2);

	if(conjugation_map.find(last_two) != conjugation_map.end()){
		vector<string> ans;
		
		for(auto suffix : conjugation_map[last_two]){
			ans.push_back(first_portion+suffix);
		}

		return ans;
	}

	return {s};
}

void testFunc(vector<string> v){
	for(string s : v){
		for(string verb : conjugate(s)){
			cout << verb << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		"comer",
		"vivir"
	});
	return 0;
}