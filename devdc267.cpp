#include <bits/stdc++.h>
#define CONST_G 9.81 // in meters per second
#define KMPH_TO_MPS (1/3.6) // 1 km/h => ? m/s
#define M_TO_KM 0.001 // 1 m => ? km
#define REACTION_TIME 1 // given that reaction time is 1s
using namespace std;

/*
Braking distance d1 is the distance a vehicle will go from the point when it brakes
to when it comes to a complete stop. It depends on the original speed v and on
the coefficient of friction mu between the tires and the road surface.

Braking distance is just one of two principal components of the total stopping distance.
The other component is the reaction distance, which is the product of the speed
and the perception-reaction time of the driver. We can just assume
that the reaction time is constant and equal to 1 second.

The kinetic energy E can be found using the formula 0.5*m*v**2,
the work W given by braking is mu*m*g*d1. Finding E and W gives
the braking distance: d1 = v*v / 2*mu*g where g is the gravity
of Earth and m the vehicle's mass.

So, to complete this challenge, there are two tasks you need to complete.

Calculate the total stopping distance in meters given v,
mu (and the reaction time t = 1).
dist(v, mu) -> d = total stopping distance

Calculate v in km per hour knowing d in meters and mu.
The reaction time is still t = 1.
speed(d, mu) -> v such that dist(v, mu) = d

Examples
dist(100, 0.7) -> 83.9598760937531

speed(83.9598760937531, 0.7) -> 100.0

Tests
dist(144, 0.3)
dist(92, 0.5)

speed(159, 0.8)
speed(153, 0.7)
*/

// speed in km/h and mu has no unit
double dist(double speed, double mu){
	double reaction_dist = speed * KMPH_TO_MPS * REACTION_TIME;
	double braking_dist = (speed * KMPH_TO_MPS) * (speed * KMPH_TO_MPS) / (2 * mu * CONST_G);

	double total_dist = reaction_dist + braking_dist; // in meters

	return total_dist;
}

// dist in meters and mu has no unit
double speed(double dist, double mu){
	double speed_in_mps = mu*CONST_G*(-REACTION_TIME + sqrt(REACTION_TIME*REACTION_TIME + 2*dist/(mu*CONST_G)));
	return speed_in_mps/KMPH_TO_MPS;
}

// main function
int main(){
	cout << dist(100, 0.7) << "\n";
	cout << speed(83.9598760937531, 0.7) << "\n";
	cout << dist(144, 0.3) << "\n";
	cout << dist(92, 0.5) << "\n";
	cout << speed(159, 0.8) << "\n";
	cout << speed(153, 0.7) << "\n";
	return 0;
}