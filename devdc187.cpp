#include <bits/stdc++.h>
using namespace std;

/*
You work in the best consumer electronics company around.
Your boss asked you to find out which products generate the most revenue.

You'll be given lists of products, amounts, and prices. Given these three
lists of same length, return the product name(s) with the highest revenue (amount * price).
If multiple products have the same revenue, order them according to their original positions.

Example
products: ["Computer", "Cell Phones", "Vacuum Cleaner"]
amounts: [8, 24, 8]
prices: [198, 9, 198]

return: Cell Phones

Test
products: ["Cell Phones", "Vacuum Cleaner", "Computer", "Autos", "Gold", "Fishing Rods", "Lego", " Speakers"]
amounts: [0, 12, 24, 17, 19, 23, 120, 8]
prices: [9, 24, 29, 31, 51, 8, 120, 14]
*/

vector<string> highestRevenue(vector<string> products, vector<int> amounts, vector<int> prices){
    vector<int> revenue; // holds the revenue of all products
    for(int i=0; i<amounts.size();i++){
        revenue.push_back(amounts[i]*prices[i]);
    }

    int max_revenue = *max_element(revenue.begin(),revenue.end()); // maximum revenue
    if(max_revenue == 0)
        return vector<string>(); // if maximum revenue is zero then there is no need to return any product

    vector<string> highestRevProducts; // vector storing the products with maximum revenue
    for(int i=0;i<revenue.size();i++)
        if(revenue[i] == max_revenue)
            highestRevProducts.push_back(products[i]);

    return highestRevProducts;
}

// main function
int main(){
    vector<string> maxRev = highestRevenue({"Computer", "Cell Phones", "Vacuum Cleaner"},{8, 24, 8},{198, 9, 198});
    for(auto s : maxRev)
        cout << s << "\n";
    return 0;
}