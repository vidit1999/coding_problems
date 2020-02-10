#include <bits/stdc++.h>
using namespace std;

/*

Implement a function that takes for input an 8x8 chessboard in the form of a bi-dimensional array.
It should return true if the black king is in check or false if it is not.

The array will include 64 squares which can contain the following characters:

♔ for the black King;
♛ for a white Queen;
♝ for a white Bishop;
♞ for a white Knight;
♜ for a white Rook;
♟ for a white Pawn;
a space if there is no piece on that square.
The board is oriented from Black's perspective. There will always be only one king (yours),
all the other pieces will be white. Remember line of sight and attack patterns of chess pieces. Input will always be valid.

Examples
Check by Queen

chessboard=[[' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ','♟',' ',' ',' ',' '],
              [' ',' ','♔',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' ']];
kingIsInCheck(chessboard) => true

Check by Bishop

 
 chessboard=[[' ',' ',' ',' ',' ',' ',' ','♝'],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              ['♔',' ',' ',' ',' ',' ',' ',' ']];
kingIsInCheck(chessboard) => true

Tests
Check by Rook

  chessboard=[[' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ','♔',' ',' ','♜',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' ']]; 
Check by Knight

  chessboard=[[' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ','♔',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              ['♞',' ',' ',' ',' ',' ',' ',' ']];     
King Alone

  chessboard=[[' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ','♔',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' '],
              [' ',' ',' ',' ',' ',' ',' ',' ']];

*/


/*
For the sake of simplicity I am using:
K ==> King, ♔
Q ==> Queen, ♛
B ==> Bisop, ♝
H ==> Knight, ♞
R ==> Rook, ♜
P ==> Pawn, ♟
*/

// returns the king's position in the board
pair<int, int> kingPosition(vector<vector<char>> board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j] == 'K'){
                return make_pair(i,j);
            }
        }
    }
}

// function to check north-south-east-west for Queen and rook
bool isNSEWSafe(int x, int y, vector<vector<char>> board){

    // north and south check
    for(int i=0;i<8;i++){
        if(i != y){
            if(board[x][i] == 'Q' || board[x][i] == 'R')
                return false;
        }
    }

    // east and west check
    for(int i=0;i<8;i++){
        if(i!=x){
            if(board[i][y] == 'Q' || board[i][y] == 'R')
                return false;
        }
    }

    return true;
}

// function to check all corner direstions NE,NW,SE,SW for Queen and Bishop
bool isCornersSafe(int x, int y, vector<vector<char>> board){
    int i=x, j=y;

    // checking north-east
    while(i >= 0 && j < 8){
        if(board[i][j] == 'Q' || board[i][j] == 'B')
            return false;
        i--;
        j++;
    }

    i=x,j=y;
    // checling north-west
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q' || board[i][j] == 'B')
            return false;
        i--;
        j--;
    }

    i=x,j=y;
    // checking south-east
    while(i < 8 && j < 8){
        if(board[i][j] == 'Q' || board[i][j] == 'B')
            return false;
        i++;
        j++;
    }

    i=x,j=y;
    // checking south-west
    while(i < 8 && j >= 0){
        if(board[i][j] == 'Q' || board[i][j] == 'B')
            return false;
        i++;
        j--;
    }

    return true;
}


// function to check if king is safe from knight
bool isSafeFromKnight(int x, int y, vector<vector<char>> board){
    if(x-2 >= 0 && y+1 < 8 && board[x-2][y+1]=='H')
        return false;
    if(x-2 >= 0 && y-1 >= 0 && board[x-2][y-1]=='H')
        return false;
    if(x+2 < 8 && y-1 >= 0 && board[x+2][y-1]=='H')
        return false;
    if(x+2 < 8 && y+1 < 8 && board[x+2][y+1]=='H')
        return false;
    if(x-1 >= 0 && y-2 >= 0 && board[x-1][y-2]=='H')
        return false;
    if(x+1 < 8 && y-2 >= 0 && board[x+1][y-2]=='H')
        return false;
    if(x+1 < 8 && y+2 < 8 && board[x+1][y+2]=='H')
        return false;
    if(x-1 >= 0 && y+2 < 8 && board[x-1][y+2]=='H')
        return false;
    return true;
}

// function to check if king is safe from pawn
bool isSafeFromPawn(int x, int y, vector<vector<char>> board){
    if(x+1 < 8 && y-1 >= 0 && board[x+1][y-1] == 'P')
        return false;
    if(x+1 < 8 && y+1 < 8 && board[x+1][y+1]=='P')
        return false;
    return true;
}

// function to see if the king is checked
bool kingIsInCheck(vector<vector<char>> board){
    pair<int, int> kingPos = kingPosition(board);
    int x = kingPos.first;
    int y = kingPos.second;

    // check north-south-east-west for Queen and rook
    if(isNSEWSafe(x,y,board) && isCornersSafe(x,y,board) && isSafeFromKnight(x,y,board) && isSafeFromPawn(x,y,board)){
        return false;
    }
    return true;
}

// function to test different cases
void testFunction(vector<vector<char>> board){
    if(kingIsInCheck(board))
        cout << "Yes\n";
    else
        cout << "No\n";
}

// main function
int main(){
    testFunction({
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','P',' ',' ',' ',' '},
        {' ',' ','K',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '}
    });
    testFunction({
        {' ',' ',' ',' ',' ',' ',' ','B'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'K',' ',' ',' ',' ',' ',' ',' '}
    });
    testFunction({
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ','K',' ',' ','R',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '}
    });
    testFunction({
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ','K',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'H',' ',' ',' ',' ',' ',' ',' '}
    });
    testFunction({
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','K',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '}
    });
    return 0;
}