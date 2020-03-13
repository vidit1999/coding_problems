#include <bits/stdc++.h>
using namespace std;

/*
Write a function that calculates body mass index
Note: bmi = weight / height ^ 2

if bmi <= 18.5 return "Underweight"
if bmi <= 25.0 return "Normal"
if bmi <= 30.0 return "Overweight"
if bmi > 30 return "Obese"
*/

string bmiCalc(float weight, float height){
    float bmi = weight/(height*height);
    if(bmi <= 18.5)
        return "Underweight";
    if(bmi <= 25)
        return "Normal";
    if(bmi <= 30)
        return "Overweight";
    return "Obese";
}

// main function
int main(){
    cout << bmiCalc(60,1.6) << "\n";
    return 0;
}