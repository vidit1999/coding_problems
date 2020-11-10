#include <bits/stdc++.h>
using namespace std;

/*
Complete the function/method so that it returns
the url with anything after the anchor (#) removed.

Examples
remove_url_anchor('dev.to#about')
returns 'dev.to'

remove_url_anchor('www.telegraph.co.uk/branding')
returns 'www.telegraph.co.uk/branding'

Tests
remove_url_anchor('www.twitter.com?page=1')
remove_url_anchor('www.twitter.com#about')
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
	cout << remove_url_anchor("dev.to#about") << "\n";
	cout << remove_url_anchor("www.telegraph.co.uk/branding") << "\n";
	cout << remove_url_anchor("www.twitter.com?page=1") << "\n";
	cout << remove_url_anchor("www.twitter.com#about") << "\n";
	return 0;
}