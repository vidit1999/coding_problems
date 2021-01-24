#include <bits/stdc++.h>
using namespace std;

/*
You're an employee at a local cafe.

You can serve 3 coffee recipes:

Black = Black Coffee
Cubano = Cubano coffee + Brown sugar
Americano = Americano coffee + Milk with 0.5% fat
... and you can add a lot of extra sugar and milk in any coffee, for example:

Black coffee + Milk with 3.2% fat + Brown sugar
Cubano coffee + Brown sugar + Brown sugar + Cane sugar
Americano coffee + Milk with 3.2% fat + Cane sugar

With the following code provided for you, can you create a Coffee
by implementing a CoffeeBuilder struct/class?

You can start from scratch or use the following code as a starting off point:

C++
struct Milk {
  float fat;
};

struct Sugar {
  std::string sort;
};

struct Coffee {
  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
};

Rust
#[derive(Debug)]
struct Coffee {
    sort: String,
    milk: Vec<Milk>,
    sugar: Vec<Sugar>,
}

#[derive(Debug)]
struct Milk {
    fat: f32,
}

#[derive(Debug)]
struct Sugar {
    sort: String,
}

struct CoffeeBuilder {
    sort: String,
    milk: Vec<Milk>,
    sugar: Vec<Sugar>,
}

Tests

A Black coffee with sugar and milk with 3.2% fat, please.
A Cubano coffee, please.
An Americano with two brown sugars, please.
*/

struct Coffee {
    string sort;
    vector<float> milk;
    vector<string> sugar;
};

string aOrAn(string word){
    unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    if(!word.empty() && vowels.find(word[0]) != vowels.end()){
        return "An";
    }
    return "A";
}

string getSugars(unordered_map<string, int> sugar_count){
    string ans = "";
    vector<string> ans_vec;

    for(auto it : sugar_count){
        ans_vec.push_back(
            ((it.second>1) ? (to_string(it.second) + " ") : "") +
            it.first + " sugar" +
            ((it.second>1) ? "s" : "")
        );
    }

    for(int i=0; i<ans_vec.size()-1; i++){
        ans += ans_vec[i] + ", ";
    }

    if(!ans_vec.empty()){
        ans += ans_vec[ans_vec.size()-1];
    }

    return ans;
}

string orderCoffee(Coffee c){
    string ans = "";
    ans += aOrAn(c.sort) + " " + c.sort + " coffee";

    float milk_sum = accumulate(c.milk.begin(), c.milk.end(), 0.0);

    unordered_map<string, int> sugar_count;

    for(auto it : c.sugar){
        sugar_count[it]++;
    }

    if(!sugar_count.empty()){
        ans += " with ";
        ans += getSugars(sugar_count);
        if(milk_sum != 0) ans += " and";
    }
    else{
        ans += " with";
    }

    if(milk_sum != 0){
        ans += " milk with " + to_string(milk_sum).substr(0, 3) + "% fat";
    }

    ans += ", please.";

    return ans;
}

// main function
int main(){
    cout << orderCoffee({"Black", {3.2}, {"Brown"}}) << "\n";
    cout << orderCoffee({"Cubano", {}, {"Brown", "Brown", "Cane"}}) << "\n";
    cout << orderCoffee({"Americano", {3.2}, {"Cane"}}) << "\n";
    return 0;
}
