#include <iostream>
using namespace std;

/*
Your task is to return a string that displays a diamond shape on the screen using asterisk (“*”) characters.

  *
 ***
*****
 ***
  *

The shape that the print method will return should resemble a diamond. A number provided as
input will represent the number of asterisks printed on the middle line.
The line above and below will be centered and will have two less asterisks than the middle line.
This reduction will continue for each line until a line with a single asterisk is printed at
the top and bottom of the figure.
Return null if input is an even number or a negative number.
Note: JS and Python students must implement diamond() method and return None (Py) or null(JS) for invalid input.

Bonus points awarded for experimenting with any extra features.
*/

void showDiamond(int n){
	if(n<0 || n%2==0)
		return;
	int asterisk_count = 1;
	int space_count = n/2;
	
	while(space_count>=0){
		for(int j=0;j<space_count;j++){
			cout << " ";
		}
		for(int j=0;j<asterisk_count;j++){
			cout << "*";
		}
		cout << "\n";
		
		if(asterisk_count==n){
			while(space_count <= n/2){
				space_count++;
				asterisk_count -= 2;
				for(int j=0;j<space_count;j++){
					cout << " ";
				}
				for(int j=0;j<asterisk_count;j++){
					cout << "*";
				}
				cout << "\n";
			}
			return;
		}
		
		space_count--;
		asterisk_count += 2;
	}	
}

// main function
int main(){
	showDiamond(43);
	return 0;
}