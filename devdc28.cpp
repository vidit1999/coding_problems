#include <bits/stdc++.h>
using namespace std;

/*
You are fighting against a monster and are strong enough to kill it with a few hits.
But after every 3 punches you make, the monster hits you once.
Your health is $h; number of monsters is $m, damage that monster can give you is $dm.

Write a function that will calculate: how many hits you received,
how much damage you received and your remaining health. If your health is <= 0,
you die and function should return "hero died".

Examples

killMonsters(100, 3, 33); // => "hits: 0, damage: 0, health: 100"
killMonsters(50, 7, 10); // => "hits: 2, damage: 20, health: 30"

Note: All numbers are strictly positive. Your function should always return a string.
*/

string killMonsters(int health, int numMons, int damage){
    int hits = (numMons-1)/3;
    int totalDamage = hits*damage;
    health -= totalDamage;
    if(health > 0)
        return "hits: " + to_string(hits) + ", damage: " + to_string(totalDamage) + ", health: " + to_string(health);
    else
        return "hero died";
}

// main function
int main(){
    cout << killMonsters(100, 3, 33) << "\n";
    cout << killMonsters(50, 7, 10) << "\n";
    return 0;
}