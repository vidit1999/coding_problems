#include <bits/stdc++.h>
using namespace std;

/*
A sandpile is a grid of piles of sand ranging from 0 to some max integer value.
For simplicity's sake, we'll look at a 3x3 grid containing 0, 1, 2, or 3 grains of sand.

An example of this sort of sandpile might look like this:

1 3 0     . ∴ 
1 2 1  =  . : .
3 2 2     ∴ : :

Sandpiles are a form of number, and as numbers, they support a single operation:
addition. To add two sandpiles, simply add the number of grains of sand within
each cell with the matching cell in the second value:

1 3 0   2 0 2   (1+2) (3+0) (0+2)   3 3 2
1 2 1 + 2 1 0 = (1+2) (2+1) (1+0) = 3 3 1
3 2 2   0 0 1   (3+0) (2+0) (2+1)   3 2 3

You probably already have wondered, what happens if the number of grains goes
above our max value of 3? The answer is, that pile topples over.
If the pile is in the middle, it dumps one grain of sand to each neighbor,
keeping whatever is left over. If it's on the edge, it loses one grain to
each direct neighbor and also loses one grain for any edges that are on the side,
which just disappear. This means that, no matter what, the over-sized cell
loses 4 grains of sand, while any neighboring cells gain 1 grain of sand.

This repeats until we've reached a state or equilibrium, like so:
                           *            *
1 3 0   3 0 2   4 3 2    * 0 5 2      2 1 3      2 1 3
1 2 1 + 2 3 0 = 3 5 1 =>   5 1 2 => * 1 3 2 =>   2 3 2 =>
3 2 2   0 0 1   3 2 3      3 3 3      4 3 3    * 0 4 3
                                                 *

                                                   *
                2 1 3    2 2 3      2 2 4      2 3 0 *
             => 2 4 2 => 3 0 4   => 3 1 0 * => 3 1 1
                1 0 4    1 2 0 *    1 2 1      1 2 1
                  *          *

So the final sum looks like this.

1 3 0   3 0 2   2 3 0
1 2 1 + 2 3 0 = 3 1 1
3 2 2   0 0 1   1 2 1

We want to create a class, Sandpile, that simulates the 3x3, max 3 sandpile.
This class should have the following properties:

The constructor optionally takes a string, which is 3 groups of 3 integers (0-9),
separated by a newline. If any of the values of the integers are over 3,
then immediately topple each pile until the Sandpile is at rest.

If no argument is provided, initialize the piles with all zeros.

There should be a toString method, which prints the sandpile the
same way as the constructor. This will be used to validate your results.

There should be an add method, which takes another Sandpile as an argument.
This method returns a new Sandpile, with the sum of the previous Sandpiles.
S
andpiles are immutable after creation

The add function will only ever receive another Sandpile instance.

Tests
Add sp1 with sp2 (no topple):
let sp1 = new Sandpile('130\n121\n322');
let sp2 = new Sandpile('202\n210\n001');
Add sp1 with sp2 (with topple):
let sp1 = new Sandpile('333\n333\n333');
let sp2 = new Sandpile('000\n010\n000');
*/


class Sandpile{
	private:
	
	int arr[3][3];
    bool equilibrium();

	public:

	Sandpile();
	Sandpile(string s);
    Sandpile(int ret[3][3]);
	Sandpile operator+(Sandpile sp);
	string toString();
};

Sandpile::Sandpile(){
    memset(arr, 0, sizeof(arr));
}

Sandpile::Sandpile(int ret[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = ret[i][j];
        }
    }
    equilibrium();
}

Sandpile::Sandpile(string s){
    int i = 0, j = 0;
    for(char c : s){
        if(c == '\n'){
            i++;
            j = 0;
        }
        else{
            arr[i][j++] = c - '0';
        }
    }
    equilibrium();
}


bool Sandpile::equilibrium(){
    bool change = false;
    int temp[3][3];
    memset(temp, 0, sizeof(temp));

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] > 3){
                change = true;
                arr[i][j] -= 4;

                for(int k=-1; k<=1; k++){
                	for(int l=-1; l<=1; l++){
                		if(
                            !(k == 0 && l == 0) &&
                            (k == 0 || l == 0)
                        ){
                			if(
                				i+k >= 0 && i+k < 3 &&
                				j+l >= 0 && j+l < 3
            				){  
                				temp[i+k][j+l] += 1; 
            				}
                		}
                	}
                }
            }
        }
    }

    for(int i=0; i<3; i++){
    	for(int j=0; j<3; j++){
    		arr[i][j] += temp[i][j];
    	}
    }

    if(change) return equilibrium();

    return false;
}

Sandpile Sandpile::operator+(Sandpile sp){
    int ret[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ret[i][j] = arr[i][j] + sp.arr[i][j];
        }
    }
    return Sandpile(ret);
}

string Sandpile::toString(){
    string ret = "";
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ret += ('0' + arr[i][j]);
        }
        if(i != 2) ret += "\\n";
    }

    return ret;
}

// main function
int main(){
	Sandpile sp1("130\n121\n322");
	Sandpile sp2("302\n230\n001");
    Sandpile sp3 = sp1 + sp2;
	
    cout << sp1.toString() << "\n";
	cout << sp2.toString() << "\n";
	cout << sp3.toString() << "\n";

    Sandpile sp4("333\n333\n333");
    Sandpile sp5("000\n010\n000");
    Sandpile sp6;
    sp6 = sp4 + sp5;

    cout << sp4.toString() << "\n";
	cout << sp5.toString() << "\n";
	cout << sp6.toString() << "\n";

	return 0;
}