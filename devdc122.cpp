#include <bits/stdc++.h>
#define N 3
using namespace std;

/*
Your objective is to complete a function createSpiral(N) that receives an integer N
and returns an NxN two-dimensional array with numbers 1 through NxN represented as a clockwise spiral.

Return an empty array if N < 1 or N is not int / number

Examples:

N = 3 Output: [[1,2,3],[8,9,4],[7,6,5]]

1 2 3

8 9 4

7 6 5

N = 4 Output: [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]

1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

N = 5 Output: [[1,2,3,4,5],[16,17,18,19,6],[15,24,25,20,7],[14,23,22,21,8],[13,12,11,10,9]]

1 2 3 4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9
*/

void fillUtil(int arr[N][N],int i, int j, int m, int n, int count){
    if(i >= m || j >= n)
        return;
    
    for(int p=i;p<n;p++)
        arr[i][p] = ++count;
    
    for(int p=i+1;p<m;p++)
        arr[p][n-1] = ++count;
    
    
    if(m-1 != i){
        for(int p =n-2;p>=j;p--)
            arr[m-1][p] = ++count;
    }

    if(n-1 != j){
        for(int p=m-2;p>i;p--)
        arr[p][j] = ++count;
    }

    fillUtil(arr, i+1, j+1, m-1, n-1, count);
}

void fillMatrix(){
    if(N > 0){
        int arr[N][N];
        int count  = 0;
        fillUtil(arr, 0, 0, N, N, count);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
}

// main function
int main(){
    fillMatrix();
	return 0;
}