#include <bits/stdc++.h>
using namespace std;

/*
Unfortunately, you have found yourself in a difficult situation.
You have injured your leg and are unable to walk.
A number n of zombies are shuffling towards you, intent on eating your brains.
Luckily, you've got your trusty rifle.

The zombies will start at a range of r meters. They will move at 0.5m per second.
Each second, you shoot one zombie, which depletes your ammo reserve a by 1 each shot.
The remaining zombies shamble forward. Since you're a good shot but also debilitated,
there's a 5% chance you might miss.

If any of the zombies manage to reach 0 meters, you get eaten and lose.
If you run out of ammo, you'll also get eaten. Ignore any time that would be spent reloading.

Write a function that accepts the total number of zombies n, a range in meters r,
and the number of bullets you have a.

If you shoot all the zombies, return "You shot all X zombies."
If you get eaten before killing all the zombies, and before running out of ammo,
return "You shot X zombies before being eaten: overwhelmed."
If you run out of ammo before shooting all the zombies,
return "You shot X zombies before being eaten: ran out of ammo."
(If you run out of ammo at the same time as the remaining zombies reach you,
return "You shot X zombies before being eaten: overwhelmed.".)

Example
zombie_shootout(3, 10, 10) => "You shot all 3 zombies."

Tests
zombie_shootout(100, 8, 200)
zombie_shootout(50, 10, 8)
*/


// takes number of bullets and percentage of missing as input
// i.e. 5 for 5% chance of missing
// this functions guarantees that the given percentage of total bullets will miss zombies
vector<bool> hitOrMiss(int numBullets,int percentage){
    vector<bool> hits(numBullets,true);
    for(int i=0;i<numBullets*percentage/100;i++){
        hits[i] = false;
    }
    shuffle(hits.begin(),hits.end(),default_random_engine(time(0)));
    return hits;
}

void zombie_shootout(int totalZombie, float range, int numBullets){
    int tempTotalZombie = totalZombie; // holds the total number of zombies
    int tempNumBullets = numBullets; // holds the total number of bullets
    vector<bool> hits = hitOrMiss(numBullets,5);

    while(numBullets>0 && totalZombie > 0 && range > 0){
        if(hits[numBullets-1]){
            totalZombie--;
        }
        numBullets--;
        if(totalZombie==0)
            break;
        range -= 0.5;
    }

    // If you shoot all the zombies
    if(totalZombie == 0 && range > 0 && numBullets >= 0){
        cout << "You shot all " << tempTotalZombie << " zombies.\n";
        return;
    }

    // If you get eaten before killing all the zombies, and before running out of ammo
    // or If you run out of ammo at the same time as the remaining zombies reach you
    if(range == 0 && totalZombie > 0 && numBullets >= 0){
        cout << "You shot " << tempTotalZombie-totalZombie << " zombies before being eaten: overwhelmed.\n";
        return;
    }

    // If you run out of ammo before shooting all the zombies,
    if(numBullets == 0 && totalZombie > 0){
        cout << "You shot "<< tempTotalZombie-totalZombie <<" zombies before being eaten: ran out of ammo.\n";
        return;
    }
}

// main function
int main(){
    zombie_shootout(3, 10, 10);
    zombie_shootout(100, 8, 200);
    zombie_shootout(50, 10, 8);
    return 0;
}