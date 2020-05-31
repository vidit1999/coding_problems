#include <bits/stdc++.h>
#define N 8
using namespace std;

/*
Given two different positions on a chessboard, find the least number of moves it would
take a knight to get from one to the other. The positions will be passed
as two arguments in algebraic notation. For example, knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.

For information on knight moves, see https://en.wikipedia.org/wiki/Knight_%28chess%29

For information on algebraic notation, see https://en.wikipedia.org/wiki/Algebraic_notation_%28chess%29
*/

bool isInsideBoard(int x, int y){
	return x >= 0 && x < N && y >= 0 && y < N;
}

int knight(string startPos, string endPos){
	pair<int, int> stPos = {startPos[0]-'a', startPos[1]-'1'};
	pair<int, int> enPos = {endPos[0]-'a', endPos[1]-'1'};
	
	int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	
	bool visited[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			visited[i][j] = false;
	
	queue<pair<pair<int, int>, int>> q; // {position, distance}
	q.push({stPos, 0});
	visited[stPos.first][stPos.second] = true;
	
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(t.first.first == enPos.first && t.first.second == enPos.second)
			return t.second;
		
		for(int i=0;i<8;i++){
			int x = t.first.first + dx[i];
			int y = t.first.second + dy[i];
			
			if(isInsideBoard(x, y) && !visited[x][y]){
				visited[x][y] = true;
				q.push({{x, y}, t.second+1});
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << knight("a3", "b5") << "\n";
	return 0;
}