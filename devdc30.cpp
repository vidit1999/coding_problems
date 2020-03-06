#include <bits/stdc++.h>
using namespace std;

/*
Your challenge today is to find the original price of a product before sales discount.

For example:

Given an item at $75 sale price after applying a 25% discount,
the function should return the original price of that item before
applying the sale percentage, which is ($100.00) of course, rounded to two decimal places.

DiscoverOriginalPrice(75, 25) => 100.00M where 75 is the sale price (discounted price),
25 is the sale percentage and 100 is the original price

Note: The return type must be of type decimal and the number must be rounded to two decimal places.
*/


float DiscoverOriginalPrice(float salePrice, float discountPct){
    return roundf(salePrice*100/(100-discountPct)*100)/100;
}

// main function
int main(){
    cout << DiscoverOriginalPrice(75, 25) << "\n";
    cout << DiscoverOriginalPrice(112.9432, 25) << "\n";
    return 0;
}