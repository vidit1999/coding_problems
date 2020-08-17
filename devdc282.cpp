#include <bits/stdc++.h>
using namespace std;

/*
The car registering system of a city assigns two types of numbers:

The Customer ID - it's a natural number between 0 and 17558423 inclusively,
which is assigned to the car buyers in the following order: the first customer
receives ID 0, the second customer receives ID 1, the third customer receives ID 2, and so on.

Number Plate - assigned to the car and contains the series ( three Latin letters from ‘a’ to ‘z’)
and the serial number (three digits from 0 to 9).
Example: aaa001. Each Number Plate is related to the given Customer ID.
For example: Number Plate aaa000 is related to Customer ID 0;
Number Plate aaa001 is related to Customer ID 1, and so on.

Write a function findPlate which takes the Customer ID as an argument,
calculates the Number Plate corresponding to this ID and returns
it as a string, considering the following:

The serial numbers start at 001, end at 999.

The series change once the serial number hits 999.
The left letter changes first, alphabetically:
aaa001...aaa999, 
baa001...baa999,
...... , 
zaa001...zaa999

As soon as the left letter reaches z and the series z** has moved through
all the serial numbers the middle letter changes alphabetically as follows:
aba001...aba999, 
bba001... bba999, 
cba001...cba999, 
......, 
zba001...zba999, 
aca001...aca999, 
bca001...bca999,

As soon as the middle letter and the left letter both reaches z
and the series zz* has moved through all its serial numbers,
the right letter changes alphabetically as follows:
aab001...aab999, 
bab001...bab999, 
cab001...cab999, 
......, 
zab001...zab999, 
abb001...abb999, 
bbb001...bbb999, 
cbb001...cbb999, 
......,
zbb001...zbb999, 
acb001...acb999, 
......, 
zzz001...zzz999

When all the possible series and their serial numbers are exhausted the last Number Plate will be zzz999.

Notes:

No spaces are allowed between the characters in the returned string.
So 'abc123' is valid, but 'a b c 1 2 3' is not.
If the serial number has less than 3 digits, the missing places should
be filled with zeroes. Example: serial number '12' should equal '012';
serial number '4' should equal '004'. Customer IDs starts with 0.

Tests

findPlate(3)
findPlate(1487)
findplate(17558423)
findPlate(234567)
*/

string findPlate(int id){
    string ser_id = to_string(id%999 + 1);
    ser_id = string(3-ser_id.length(), '0' ) + ser_id;
    
    id /= 999;

    string letters = "";
    letters += (id%26 + 'a');
    letters += ((id/26)%26 + 'a');
    letters += ((id/(26*26))%26 + 'a');

    return letters + ser_id;
}

// main function
int main(){
    cout << findPlate(3) << "\n";
    cout << findPlate(1487) << "\n";
    cout << findPlate(17558423) << "\n";
    cout << findPlate(234567) << "\n";
    cout << findPlate(1000) << "\n";
    cout << findPlate(234567) << "\n";
    return 0;
}