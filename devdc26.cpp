#include <bits/stdc++.h>
using namespace std;

/*
Develop a ranking system where we can sort points and calculate
the position of an individual or a team competing in a game/competition.

Note:
If two or more persons have the same number of points,
they should have same position number and sorted by name (name is unique).

For example, Input structure:

[
  {
    name: "John",
    points: 100,
  },
  {
    name: "Bob",
    points: 130,
  },
  {
    name: "Mary",
    points: 120,
  },
  {
    name: "Kate",
    points: 120,
  },
]
Output should be:

[
  {
    name: "Bob",
    points: 130,
    position: 1,
  },
  {
    name: "Kate",
    points: 120,
    position: 2,
  },
  {
    name: "Mary",
    points: 120,
    position: 2,
  },
  {
    name: "John",
    points: 100,
    position: 4,
  },
]
*/

class namePoints{
    public:
    string name;
    int point;
    int position;

    namePoints(string name, int point){
        this->name = name;
        this->point = point;
        this->position = 0;
    }
};

// custom comparator for comparing name points
bool compareNamePoints(const namePoints& n1, const namePoints& n2){
    if(n1.point == n2.point){
        return n1.name < n2.name;
    }
    return n1.point > n2.point;
}

// sorts a list of names of points and set positions
void sortList(vector<namePoints>& position){ 
    sort(position.begin(),position.end(),compareNamePoints);
    for(int i=0;i<position.size();i++){
        position[i].position = i+1; 
    }
}

// main function
int main(){
    vector<string> names = {"John","Bob","Mary","Kate"};
    vector<int> points = {100,130,120,120};
    vector<namePoints> v;
    for(int i=0;i<4;i++){
        v.push_back(namePoints(names[i],points[i]));
    }
    for(auto it : v){
        cout << it.name << " " << it.point << "\n";
    }
    cout << "\n----------------\n";
    sortList(v);
    for(auto it : v){
        cout << it.name << " " << it.point << " " << it.position << "\n";
    }
    return  0;
}