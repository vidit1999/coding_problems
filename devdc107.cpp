#include <bits/stdc++.h>
#define N 5
#define M 5
using namespace std;

/*
A poor miner is trapped in a mine and you have to help him to get out!
The mine is completely dark so you have to tell him where to go.

Implement a method solve(cave_map, miner, exit) that has to return the path the
miner must take to reach the exit as an array of moves: ['up', 'down', 'right', 'left'].
Those are the only four possible moves as the miner cannot move diagonally.

cave_map is a 2-dimensional array of Boolean values, representing squares. false for walls,
true for open space. It will never be larger than 5 x 5. It is laid out as an array of columns.
All columns will always be the same size, though not necessarily the same size as rows
(in other words, maps can be rectangular). The map will never contain any loop,
so there will always be only one possible path. The map may contain dead-ends though.

miner is the position of the miner at the start, as an object made of two zero-based
integer properties, x and y. For example (0,0) would be the top-left corner.

exit is the position of the exit, in the same format as miner.

Note that the miner can't go outside the map, as it is a tunnel.

Let's take a pretty basic example :

cave_map = [[true, false],
    [true, true]];
solve(cave_map, (0,0), (1,1));
// Should return ['right', 'down']
Challenge maps:
A simple map. (2x2)
cave_map = [[true, false],
[true, true]];
miner = (0,0)
exit = (1,0)

A linear map. (1x4)
cave_map = [[true], [true], [true], [true]];
miner = (0,0)
exit = (3,0)

Walk around an obstacle (3x3)
cave_map = [[true, true, true],
[false, false, true],
[true, true, true]];
miner = (0,0)
exit = (2,0)
*/

bool isValid(bool arr[M][N], int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N && arr[x][y];
}

string getDirec(pair<int, int> start, pair<int, int> end){
    if(end.first - start.first == 1)
        return "right";
    else if(end.first - start.first == -1)
        return "left";
    else if(end.second - start.second == 1)
        return "down";
    else if(end.second - start.second == -1)
        return "up";
    return "default";
}

bool solve(bool arr[M][N], vector<string>& ans, int x, int y, int prev_x, int prev_y, pair<int, int> end){
    if(x == end.first && x == end.second){
        ans.push_back(getDirec(make_pair(prev_x, prev_y), make_pair(x, y)));
        return true;
    }
    arr[x][y] = false;
    ans.push_back(getDirec(make_pair(prev_x, prev_y), make_pair(x, y)));
    if(
        (isValid(arr, x-1, y) && solve(arr, ans, x-1, y, x, y, end)) ||
        (isValid(arr, x+1, y) && solve(arr, ans, x+1, y, x, y, end)) ||
        (isValid(arr, x, y-1) && solve(arr, ans, x, y-1, x, y, end)) ||
        (isValid(arr, x, y+1) && solve(arr, ans, x, y+1, x, y, end))
    ){
        return true;
    }
    arr[x][y] = true;
    ans.pop_back();
    return false;
}

// main function
int main(){
    bool arr[M][N] = {
        {true, true, false, false, false},
        {false, true, true, false, false},
        {false, false, true, true, false},
        {false, false, false, true, true},
        {false, false, false, false, true}
    };
    vector<string> ans = {};
    solve(arr, ans, 0, 0, 0, 0, {4,4});
    for(auto it : ans){
        cout << it << "\n";
    }
    return 0;
}