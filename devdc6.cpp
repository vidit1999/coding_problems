#include <bits/stdc++.h>
using namespace std;

/*

https://www.codewars.com/kata/help-your-granny/javascript

Your granny, who lives in town X0, has friends. These friends are given in an array,
for example: array of friends is [ "A1", "A2", "A3", "A4", "A5" ].

Note: the order of friends is this array and it must not be changed since this order
gives the order in which they will be visited.

These friends inhabit towns and you have an array with friends and towns, for example:
(C/CPP)
{"A1", "X1", "A2", "X2", "A3", "X3", "A4", "X4"}
which means A1 is in town X1, A2 in town X2... It can happen that we don't know the town of one of the friends.

For the distance, fortunately, you have a map (and a hashmap) that gives each distance X0X1, X0X2 and so on.
For example:
(C/CPP)
{"X1", "100.0", "X2", "200.0", "X3", "250.0", "X4", "300.0"}

which means that X1 is at 100.0 miles from X0, X2 at 200.0 miles from X0, etc...
More fortunately (it's not real life, it's a story...), the towns X0, X1, ..Xn are placed in the following manner:
X0X1X2 is a right triangle with the right angle in X1, X0X2X3 is a right triangle with the right angle in X2, etc...
If a town Xi is not visited you will suppose that the triangle X0Xi-1Xi+1 is still a right triangle.

Can you help your granny and give her the distance to travel?

You will make the circuit that permits her to visit her friends. For example here the circuit will contain:
X0, X1, X2, X3, X4, X0 

and you must compute the total distance
X0X1 + X1X2 + .. + X4X0. (Required Answer)


*/

// build map from distance from friends array
unordered_map<string, string> distOfFriends(string distFromFriends[], int n){
	unordered_map<string, string> umap;
	for(int i=0;i<n;i+=2){
		umap[distFromFriends[i]] = distFromFriends[i+1];
	}
	return umap;
}

// build map from distance from X0
unordered_map<string , float> dist(string distFromX0[], int n){
	unordered_map<string, float> umap;
	for(int i=0;i<n;i+=2){
		umap[distFromX0[i]] = stof(distFromX0[i+1]);
	}
	return umap;
}

// get distance from one city to another
float getDistance(string currentCity, string nextCity, unordered_map<string , float> distance){
	if(nextCity == currentCity)
		return 0;
	if(currentCity == "X0"){
		return distance[nextCity];
	}
	// X0X(curr)X(next) is right triangle with right angle at X(curr)
	// [X0X(curr)]^2 + [X(curr)X(next)]^2 = [X0X(next)]^2
	// [X(curr)X(next)]^2 = [X0X(next)]^2 - [X0X(curr)]^2
	float dist = sqrtf(distance[nextCity]*distance[nextCity] - distance[currentCity]*distance[currentCity]);
	return dist;
}

// returns the total distance
float totalDistance(string friends[],string distFromFriends[],string distFromX0[], int n1, int n2, int n3){
	unordered_map<string, string> cities = distOfFriends(distFromFriends,n2);
	unordered_map<string , float> distance = dist(distFromX0,n3);
	float total = 0;
	string currentCity = "X0";
	string nextCity;
	cout << currentCity << " ";
	
	for(int i=0;i<n1;i++){
		nextCity = cities[friends[i]];
		cout << nextCity << " ";
		total += getDistance(currentCity, nextCity, distance);
		currentCity = nextCity;
	}
	currentCity = "X0";
	cout << currentCity << "\n";
	total += getDistance(currentCity, nextCity, distance);
	return total;
}

// main function
int main(){
	string friends[] = {"A1", "A2", "A3", "A4"};
	string distFromFriends[] = {"A1", "X1", "A2", "X2", "A3", "X3", "A4", "X4"};
	string distFromX0[] = {"X1", "100.0", "X2", "200.0", "X3", "250.0", "X4", "300.0"};
	int n1 = sizeof(friends)/sizeof(friends[0]);
	int n2 = sizeof(distFromFriends)/sizeof(distFromFriends[0]);
	int n3 = sizeof(distFromX0)/sizeof(distFromX0[0]);
	cout << totalDistance(friends,distFromFriends,distFromX0,n1,n2,n3) << "\n";
	
	return 0;
}