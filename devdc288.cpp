#include <bits/stdc++.h>
using namespace std;

#define N 7

/*
Welcome, Adventurer. Your aim is to navigate the maze and reach the finish point
without touching any walls. Doing so will kill you instantly!

You will be given a 2D array of the maze and an array of directions.
Your task is to follow the directions given. If you reach the end point
before all your moves have gone, you should return Finish. If you hit
any walls or go outside the maze border, you should return Dead.
If you find yourself still in the maze after using all the moves,
you should return Lost.

The Maze array will look like
maze = [[1,1,1,1,1,1,1],
        [1,0,0,0,0,0,3],
        [1,0,1,0,1,0,1],
        [0,0,1,0,0,0,1],
        [1,0,1,0,1,0,1],
        [1,0,0,0,0,0,1],
        [1,2,1,0,1,0,1]]
..with the following key
      0 = Safe place to walk
      1 = Wall
      2 = Start Point
      3 = Finish Point
For the above example, direction = ["N","N","N","N","N","E","E","E","E","E"]
should get you to the end!

Rules
The Maze array will always be square i.e.
N x N but its size and content will alter from test to test.

The start and finish positions will change for the final tests.

The directions array will always be in upper case and will be in the
format of N = North, E = East, W = West and S = South.

If you reach the end point before all your moves have gone, you should return Finish.

If you hit any walls or go outside the maze border, you should return Dead.

If you find yourself still in the maze after using all the moves, you should return Lost.
Good luck, and stay safe!

Tests
Maze:
var maze = [[1,1,1,1,1,1,1],
            [1,0,0,0,0,0,3],
            [1,0,1,0,1,0,1],
            [0,0,1,0,0,0,1],
            [1,0,1,0,1,0,1],
            [1,0,0,0,0,0,1],
            [1,2,1,0,1,0,1]];
Tests
["N","N","N","N","N","E","E","E","E","E"]
["N","N","N","W","W"]
["N","E","E","E","E"]
*/

bool isValid(pair<int, int> pos, int maze[N][N]){
	return (
		pos.first >= 0 && pos.first < N &&
		pos.second >= 0 && pos.second < N &&
		(maze[pos.first][pos.second] != 1)
	);
}

pair<pair<int, int>, pair<int, int>> findStartEnd(int maze[N][N]){
	pair<int, int> start, end;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(maze[i][j] == 2)
				start = {i, j};
			else if(maze[i][j] == 3)
				end = {i, j};
		}
	}
	return {start, end};
}

pair<int, int> getNextPos(pair<int, int> start, char direction){
	switch(direction){
		case 'N' : return {start.first - 1, start.second};
		case 'S' : return {start.first + 1, start.second};
		case 'E' : return {start.first, start.second + 1};
		case 'W' : return {start.first, start.second - 1};
	}
	return {-1, -1};
}

string mazeRunner(int maze[N][N], vector<char> directions){
	auto startEnd = findStartEnd(maze);
	auto start = startEnd.first, end = startEnd.second;
    if(start == end) return "Finish";

	for(auto direction : directions){
		pair<int, int> next_pos = getNextPos(start, direction);
		if(!isValid(next_pos, maze)) return "Dead";
		start = next_pos;
        if(start == end) return "Finish";
	}

	return "Lost";
}

// main function
int main(){
	int maze[N][N] = {
		{1,1,1,1,1,1,1},
		{1,0,0,0,0,0,3},
		{1,0,1,0,1,0,1},
		{0,0,1,0,0,0,1},
		{1,0,1,0,1,0,1},
		{1,0,0,0,0,0,1},
		{1,2,1,0,1,0,1}
	};
	
	vector<vector<char>> v = {
		{'N','N','N','N','N','E','E','E','E','E'},
		{'N','N','N','W','W'},
		{'N','E','E','E','E'},
	};

	for(auto directions : v){
		cout << mazeRunner(maze, directions) << "\n";
	}
	return 0;
}