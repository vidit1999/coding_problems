#include <bits/stdc++.h>
using namespace std;

/*
Bob's coffee shop is really busy, so busy in fact that if you do not
have the right amount of change, you won't get your coffee as Bob doesn't
like waiting for people to sort change. Drinks avaialble are Americano
£2.20, Latte £2.30, Flat white £2.40 and Filter £3.50

Write a function that returns, "Here is your "+type+", have a nice day!"
if they have the right change or returns "Sorry, exact change only, try again tomorrow!"
*/

string coffeShop(float amount){
    unordered_map<float, string> drinks = {{2.2,"Americano"},{2.3,"Latte"},{2.4,"Flat white"},{3.5,"Filter"}};
    if(drinks[amount].empty())
        return "Sorry, exact change only, try again tomorrow!";
    return "Here is your "+drinks[amount]+", have a nice day!";
}

// main function
int main(){
    cout << coffeShop(2.2) << "\n";
    cout << coffeShop(2.3) << "\n";
    cout << coffeShop(2.4) << "\n";
    cout << coffeShop(3.5) << "\n";
    cout << coffeShop(2.20) << "\n";
    cout << coffeShop(2.19) << "\n";
    return 0;
}