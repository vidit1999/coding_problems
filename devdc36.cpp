#include <bits/stdc++.h>
using namespace std;

/*
Today's challenge requires you to calculate one's running pace.

For example:

runningPace(distance, time)
distance - A float with the number of kilometres
time - A string containing the time it took to travel the distance; it will always be minutes:seconds

The function should return the pace, "5:20" means it took 5 minutes and 20 seconds to travel one kilometre.
*/

// returns the running pace
string runningPace(float distance, string time){
    // get time in seconds from given string time
    float timeSec = 0;
    string t = "";
    timeSec += 60*atoi(time.substr(0,time.find(':')+1).c_str());
    timeSec += atoi(time.substr(time.find(':')+1,time.length()-time.find(':')-1).c_str());
    int speed = distance/timeSec;

    return to_string(speed/60)+":"+to_string(speed%60);
}

// main function
int main(){
    cout << runningPace(18000,"3:00") << "\n";
    return 0;
}