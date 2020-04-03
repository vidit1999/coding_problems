#include <bits/stdc++.h>
using namespace std;

/*
Your strict math teacher is teaching you about right triangles and
the Pythagorean Theorem --> a^2 + b^2 = c^2 whereas a and b are the legs of the right triangle
and c is the hypotenuse of the right triangle.

On the test, however, the question asks: What are the possible integer lengths for
the other side of the triangle?. Since you never learned anything about that in class,
you realize she meant What are the possible integer lengths for the other side of the right triangle?.

Because you want to address the fact that she asked the wrong question and the fact
that you're smart at math, you've decided to answer all the possible values for
the third side EXCLUDING the possibilities for a right triangle in increasing order.

Return your answer as a list of all the possible third side lengths of the
triangle without right triangles in increasing order.

Examples
side_len(1, 1) --> [1]
side_len(3, 4) --> [2, 3, 4, 6]
side_len(4, 6) -->[3, 4, 5, 6, 7, 8, 9]

Tests
side_len(5, 12)
side_len(8, 10)
side_len(3, 4)
*/

// check if three integers a, b, c can form a right triangle
bool pythagoreanTriplet(int a, int b, int c){
    return (a*a + b*b == c*c) || (a*a + c*c == b*b) || (c*c + b*b == a*a);
}

// returns a vector of all the possible third side lengths
// without right triangles in increasing order
vector<int> side_len(int a, int b){
    vector<int> thirdSide;
    int start = abs(b - a) + 1;
    int end = b + a - 1;

    for(int i=start; i<=end; i++){
        if(!pythagoreanTriplet(a, b, i))
            thirdSide.push_back(i);
    }

    return thirdSide;
}

void testFunc(int a, int b){
    for(auto it : side_len(a, b)){
        cout << it << "  ";
    }
    cout << "\n";
}

// main function
int main(){
    testFunc(1, 1);
    testFunc(3, 4);
    testFunc(4, 6);
    testFunc(5, 12);
    testFunc(8, 10);
    return 0;
}