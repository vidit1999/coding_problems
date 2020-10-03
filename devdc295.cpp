#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, you'll be given a leaderboard in the form of an array,
as well as a list of strings. Using the information in the list, sort the leaderboard.

Example
array:
['John',
 'Brian',
 'Jim',
 'Dave',
 'Fred']
list:
['Dave +1', 'Fred +4', 'Brian -1']

The steps for our example would be:
# Dave up 1
['John',
 'Brian',
 'Dave',
 'Jim',
 'Fred']
# Fred up 4
['Fred',
 'John',
 'Brian',
 'Dave',
 'Jim']
# Brian down 1
['Fred',
 'John',
 'Dave',
 'Brian',
 'Jim']
Then, we return the completed leaderboard:
['Fred',
 'John',
 'Dave',
 'Brian',
 'Jim']

Strings will never ask you to move a name higher or lower than possible.
The strings in the list will always be a name in the leaderboard,
followed by a space and a positive or negative number.

Tests
leaderboardSort(['John', 'Brian', 'Jim', 'Dave', 'Fred'], ['Dave +1', 'Fred +4', 'Brian -1'])
leaderboardSort(['Bob', 'Larry', 'Kevin', 'Jack', 'Max'], ['Max +3', 'Kevin -1', 'Kevin +3'])
*/

vector<pair<string, int>> positionToAdd(vector<string>& positions_add){
	vector<pair<string, int>> name_pos;

	for(auto s : positions_add){
		string temp = "";
		string name;
		int to_add, sign;

		for(char c : s){
			if(c == ' '){
				name = temp;
				temp = "";
			}
			else if(c == '-' || c == '+'){
				sign = (c == '+')? 1 : -1;
			}
			else{
				temp += c;
			}
		}

		to_add = stoi(temp);
		name_pos.push_back({name, sign*to_add});
	}

	return name_pos;
}

int getNameIndex(vector<string>& names, string name){
    for(int i=0; i<names.size(); i++){
        if(names[i] == name){
            return i;
        }
    }
    return -1;
}

void leaderboardSort(vector<string>& names, vector<string>& positions_add){
	auto positions_to_add = positionToAdd(positions_add);

    for(auto it : positions_to_add){
        string name = it.first;
        int to_add = it.second;
        int direction = (to_add > 0)? -1 : 1;
        to_add = abs(to_add);
        
        int index = getNameIndex(names, name);

        while(to_add > 0){
            swap(names[index], names[index + direction]);
            index += direction;
            to_add--;
        }
    }
}

void testFunc(vector<pair<vector<string>, vector<string>>> v){
    for(auto p : v){
        leaderboardSort(p.first, p.second);
        for(string s : p.first){
            cout << s << " ";
        }
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {
            {"John", "Brian", "Jim", "Dave", "Fred"},
            {"Dave +1", "Fred +4", "Brian -1"}
        },
        {
            {"Bob", "Larry", "Kevin", "Jack", "Max"},
            {"Max +3", "Kevin -1", "Kevin +3"}
        }
    });

	return 0;
}