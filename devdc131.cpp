#include <bits/stdc++.h>
using namespace std;

/*
Complete the function/method so that it returns the URL with anything after the anchor (#) removed.

Examples

# returns 'www.codewars.com'
remove_url_anchor('www.codewars.com#about')

# returns 'www.codewars.com?page=1'
remove_url_anchor('www.codewars.com?page=1')
*/

string remove_url_anchor(string url){
	string ans = "";
	for(char c : url){
		if(c == '#')
			break;
		ans += c;
	}
	return ans;
}

// main function
int main(){
	cout << remove_url_anchor("www.codewars.com#about") << "\n";
	cout << remove_url_anchor("www.codewars.com?page=1") << "\n";
	return 0;
}