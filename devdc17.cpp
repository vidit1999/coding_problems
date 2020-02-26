#include <bits/stdc++.h>
using namespace std;

/*
Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola"
drink vending machine; there are no other people in the queue. The first one
in the queue (Sheldon) buys a can, drinks it and doubles! The resulting two
Sheldons go to the end of the queue. Then the next in the queue (Leonard) buys a can,
drinks it and gets to the end of the queue as two Leonards, and so on.

For example, Penny drinks the third can of cola and the queue will look like this:
Rajesh, Howard, Sheldon, Sheldon, Leonard, Leonard, Penny, Penny

Write a program that will return the name of the person who will drink the n-th cola.
The input data consist of an array which contains at least 1 name, and single integer n
which may go as high as the biggest number your language of choice supports
(if there's such limit, of course). The output data returns the single line — the
name of the person who drinks the n-th can of cola. The cans are numbered starting from 1.

const cola = (number, people) => {
  const length = people.length;
  const iteration = Math.floor(Math.log2(((number - 1) / length) + 1));
  const post = 2 ** iteration;

  return people[Math.floor((number - ((post - 1) * length + 1)) / post)]
}
*/


string drinkerOfNthCola(vector<string> names, int n){
    int length  = names.size();
    int iteration = floor(log2(((n-1)/length)+1));
    int post = pow(2,iteration);
    return names[floor((n - ((post-1)*length + 1))/post)];
}

// main function
int main(){
    vector<string> v = {"Sheldon", "Leonard", "Penny", "Rajesh" , "Howard"};
    cout << drinkerOfNthCola(v,10);
    return 0;
}