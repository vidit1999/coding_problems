#include <bits/stdc++.h>
using namespace std;

/*
Implement a function called SnakesLadders to play a two-player game of Snakes and Ladders.
The function should keep track of player turns and player position on the board (of the 100 spaces). 
SnakesLadders should call a method play(die1, die2) independently of the state of the game or the player turn.
These variables are the die thrown in a turn and are both integers between 1 and 6. The player moves the sum of die1 and die 2.

Snakes and Ladder positions :{
	[99,80],
	[95,75],
	[92,88],
	[89,68],
	[74,53],
	[64,60],
	[62,19],
	[49,11],
	[46,25],
	[16,6], // Upto this are snakes
	
	[2,38], // From this are ladders
	[7,14],
	[8,31],
	[15,26],
	[21,42],
	[28,84],
	[36,44],
	[51,67],
	[71,91],
	[78,98],
	[87,94]
}

Rules ::--

There are two players and both start off the board on square 0.

Player 1 starts and alternates with player 2.

You follow the numbers up the board in order 1=>100

If the value of both die are the same then that player will have another go.

Climb up ladders. The ladders on the game board allow you to move upwards and get ahead faster.
If you land exactly on a square that shows an image of the bottom of a ladder, then you may move
the player all the way up to the square at the top of the ladder. (even if you roll a double).

Slide down snakes. Snakes move you back on the board because you have to slide down them.
If you land exactly at the top of a snake, slide move the player all the way to the square at
the bottom of the snake or chute. (even if you roll a double).

Land exactly on the last square to win. The first person to reach the highest square on the board wins.
But there's a twist! If you roll too high, your player "bounces" off the last square and moves back.
You can only win by rolling the exact number needed to land on the last square. For example,
if you are on square 98 and roll a five, move your game piece to 100 (two moves), then "bounce" back to
99, 98, 97 (three, four then five moves.)

Return Player n Wins!. Where n is winning player that has landed on square 100 without any remaining moves left.

Return Game over! if a player has won and another player tries to play.

Otherwise return Player n is on square x. Where n is the current player and x is the square they are currently on.
*/

// returns the sum of numbers in die1 and die2 and also whether they are same or not
// Example : die1 = 4, die2 = 5  => return <9, false>
// Example : die1 = 3, die2 = 3  => return <6, true>
pair<int, bool> play(){
	int die1 = rand()%6 + 1;
	int die2 = rand()%6 + 1;
	
	return make_pair(die1 + die2, die1==die2);
}

// main snake and ladder game
void SnakesLadders(){
	srand(time(0));
	
	// differnt positions of snake and ladders
	// first one is starting position and second one is ending position
	unordered_map<int, int> snakeLadderPos = {
		{99,80},
		{95,75},
		{92,88},
		{89,68},
		{74,53},
		{64,60},
		{62,19},
		{49,11},
		{46,25},
		{16,6},
		{2,38},
		{7,14},
		{8,31},
		{15,26},
		{21,42},
		{28,84},
		{36,44},
		{51,67},
		{71,91},
		{78,98},
		{87,94}
	};
	
	int playerPos[2] = {0,0}; // positions of player1 and player2 respectively
	int turn = 0; // 0 if it is player1's turn, 1 if player2's turn
	
	while(true){
		pair<int, bool> move = play(); // roll the dies
		playerPos[turn] += move.first; // make the move

        // prints the move
        cout << "Player " << turn+1 << "'s turn : " << move.first;
        if(move.second)
            cout << " and double chance";
        cout << "\n";
        
		// bounce off if move takes player to position greater than 100
        if(playerPos[turn] > 100){
            cout << "Player " << turn+1 << " bounces off from " << playerPos[turn] << " to ";
			playerPos[turn] = 200 - playerPos[turn];
            cout << playerPos[turn] << ".\n";
        }

        // if snake or ladder then go the position indicated
		if(snakeLadderPos.find(playerPos[turn]) != snakeLadderPos.end()){
            if(playerPos[turn] > snakeLadderPos[playerPos[turn]])
                cout << "Player " << turn+1 << " is snaked from " << playerPos[turn] << " to ";
            else
                cout << "Player " << turn+1 << " is laddered from " << playerPos[turn] << " to ";
			playerPos[turn] = snakeLadderPos[playerPos[turn]];
			cout  << playerPos[turn] << "\n";
        }
		
        
		// this part handles the case if the player reaches the goal or not
        // if goal is reached then prints the winner and break the loop
		if(playerPos[turn] == 100){
            cout << "Player " << turn+1 << " wins!\nGame over for Player " << 2-turn << ".\n";
			break;
		}
		
		// if player does not have a second move
		// then its turn for other player
		if(!move.second)
			turn = 1 - turn;
		cout << "Player 1 is on square "<< playerPos[0] << ".\n";
		cout << "Player 2 is on square "<< playerPos[1] << ".\n\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // prints after 0.5sec gap
	}
}

// main function
int main(){
	SnakesLadders();
	return 0;
}