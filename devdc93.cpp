#include <bits/stdc++.h>
using namespace std;

/*
A format for expressing an ordered list of integers is to use a comma separated list of either:

individual integers
a range of integers denoted by the starting integer separated from the end integer in the range by a dash, -.
the range includes all integers in the interval including both endpoints.
It is not considered a range unless it spans at least 3 numbers. For example 12, 13, 15-17

Complete the solution so that it takes a list of integers in increasing order
and returns a correctly formatted string in the range format.

Example:

solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20])

returns (-6,-3-1,3-5,7-11,14,15,17-20)
*/

vector<string> solution(vector<int> lst){
	if(lst.size() < 3){
		vector<string> v;
		for(int i : lst)
			v.push_back(to_string(i));
		return v;
	}
	
	vector<string> v;
	int start_range_number = lst[0], start_index = 0;
	
	int i;
	for(i=1;i<lst.size();i++){
		if(lst[i] != lst[i-1]+1){
			if(i - start_index >= 3){
				v.push_back(to_string(lst[start_index])+"-"+to_string(lst[i-1]));
			}
			else{
				for(int j=start_index;j<i;j++)
					v.push_back(to_string(lst[j]));
			}
			start_range_number = lst[i];
			start_index = i;
		}
	}
	if(start_index < lst.size()){
		if(i - start_index >= 3){
			v.push_back(to_string(lst[start_index])+"-"+to_string(lst[i-1]));
		}
		else{
			for(int j=start_index;j<i;j++)
				v.push_back(to_string(lst[j]));
		}
	}
	return v;
}

// main function
int main(){
	for(string s : solution({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}))
		cout << s << "\n";
	return 0;
}