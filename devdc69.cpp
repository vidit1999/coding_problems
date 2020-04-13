#include <bits/stdc++.h>
using namespace std;

/*
John likes to go to the cinema, but he wants to find the most cost-effective way to go.
He can buy a ticket for $15, or he can buy a membership card for $500.
Every time he uses the membership card, the ticket will be 0.9 times the price he paid for the last one.

Ex. If John goes to the cinema three times:
A : 15 * 3 = 45
B : 500 + 15 * 0.90 + (15 * 0.90) * 0.90 + (15 * 0.90 * 0.90) * 0.90
( = 536.5849999999999, no rounding for each ticket)

Create a function movie with three parameters: card (price of the card),
ticket(normal price of a ticket), perc(fraction of what he paid for the previous ticket)
and returns the first n such that ceil(price of B) < price of A

More examples:
movie(500, 15, 0.9)should return43
(with card the total price is 634, with tickets 645)

movie(100, 10, 0.95) should return 24
(with card the total price is 235, with tickets 240)
*/

int movie(double card, double ticket, double perc){
	int n = 0;
	double priceUsingCard = card;
	double priceNotUsingCard = 0;
	double fractionTicket = ticket;
	
	while(priceUsingCard >= priceNotUsingCard){
		priceNotUsingCard += ticket;
		fractionTicket *= perc;
		priceUsingCard += fractionTicket;
		n++;
	}
	return n;
}

// main function
int main(){
	cout << movie(500, 15, 0.9) << "\n";
	cout << movie(100, 10, 0.95) << "\n";
	return 0;
}