#include <bits/stdc++.h>
using namespace std;

/*
Your goal is to create a function that takes a positive
integer and returns the next bigger number formed using the same digits.

A number like 2019 would not become 9210, as that is the largest possible
number that can be created using those digits. The answer would be 2091,
as that is the next larger number.

For example:
12 ==> 21
513 ==> 531

If a larger number cannot be composed using those digits, return -1 or null.
*/

int nextLargeNumber(int number){
    // create a vector from digits of number
    vector<int> digits;
    while(number){
        digits.push_back(number%10);
        number /= 10;
    }
    // at this point of time array is [1,2,5,3] so reversing it to [3,5,2,1]
    reverse(digits.begin(),digits.end());

    // start scanning from backward
    // if a digit is grater than its next digit swap them
    // sort the array from the position where the scanning pointer is to end
    // [3,5,2,1]
    // 5 > 3 so swap 3 and 5
    // after swaping ==> [5,3,2,1]
    // sort from 3 to 1
    // after sorting [5,1,2,3] required integer will be 5123

    int pos = digits.size() - 1;
    while(pos > 0){
        if(digits[pos] > digits[pos-1]){
            swap(digits[pos], digits[pos-1]);
            sort(digits.begin()+pos,digits.end());
            int num = 0;
            for(int i=0;i<digits.size();i++){
                num *= 10;
                num += digits[i];
            }
            return num;
        }
        pos--;
    }
    return -1;
}

// main function
int main(){
    cout << nextLargeNumber(3521) << "\n";
    cout << nextLargeNumber(12) << "\n";
    cout << nextLargeNumber(513) << "\n";
    cout << nextLargeNumber(351) << "\n";
    cout << nextLargeNumber(999) << "\n";
    cout << nextLargeNumber(0) << "\n";
    cout << nextLargeNumber(9) << "\n";
    return 0;
}