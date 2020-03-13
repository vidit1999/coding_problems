#include <bits/stdc++.h>
using namespace std;

/*
Minecraft has gotten to be a very popular game.
No doubt many reading this have played it themselves or watched someone else.
In Minecraft, collected ore must be smelted in a furnace to change the resource into a usable form.

Each ingot takes 11 seconds to produce. Steve has the following fuel options to add to the furnace:

Buckets of lava, each lasts 800 seconds
Blaze rod, each lasts 120 seconds
Coals, each lasts 80 seconds
Blocks of Wood, each lasts 15 seconds
Sticks, each lasts 1 second*

Write a function that calculates the minimum amount of fuel needed to produce a certain number of iron ingots.

Ruby: {:lava => 2, :blaze_rod => 1, :coal => 1, :wood => 0, :stick => 0}
JavaScript: {lava: 2, blazeRod: 1, coal: 1, wood: 0, stick: 0}
*/

unordered_map<string,int> minFuelNum(int numberIngots){
    unordered_map<string, int> options;
    int timeNeeded = 11*numberIngots;
    options["lava"] = timeNeeded/800;
    timeNeeded %= 800;
    options["blazeRod"] = timeNeeded/120;
    timeNeeded %= 120;
    options["coal"] = timeNeeded/80;
    timeNeeded %= 80;
    options["wood"] = timeNeeded/15;
    timeNeeded %= 15;
    options["stick"] = timeNeeded;
    return options;
}

// main function
int main(){
    for(auto option : minFuelNum(150))
        cout << option.first << " -- " << option.second << "\n";
    return 0;
}