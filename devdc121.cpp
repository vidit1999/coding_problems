#include <bits/stdc++.h>
using namespace std;

/*
You're going on a trip with some students and it's up to you to keep track of how much
money each Student has. A student is defined like this:

class Student:
def __init__(self, name, fives, tens, twenties):
self.name = name
self.fives = fives
self.tens = tens
self.twenties = twenties

As you can tell, each Student has some fives, tens, and twenties. Your job is to
return the name of the student with the most money. If every student has the same amount, then return "all".

Notes:

Each student will have a unique name
There will always be a clear winner: either one person has the most, or everyone has the same amount
If there is only one student, then that student has the most money
*/

class Student{
	string name;
	int fives, tens, twenties;
	
	public:
	
	Student(string name, int fives=0, int tens=0, int twenties=0){
		this->name = name;
        this->fives = fives;
        this->tens = tens;
        this->twenties = twenties;
	}

    int getAmount(){
        return this->fives + this->tens + this->twenties;
    }

    string getName(){
        return this->name;
    }
};

string mostMoney(vector<Student> arr){
    if(arr.size() == 0)
        return "";
    if(arr.size() == 1)
        return arr[0].getName();
    
    string mostMoneyName = arr[0].getName();
    int amount = arr[0].getAmount();
    bool allSame = true;

    for(auto it : arr){
        if(it.getAmount() != amount)
            allSame = false;
        if(amount < it.getAmount()){
            amount = it.getAmount();
            mostMoneyName = it.getName();
        }
    }

    return (allSame)? "all" : mostMoneyName;
}

// main function
int main(){
	return 0;
}