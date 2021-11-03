#include<iostream>
using namespace std;

#define QUARTER 25
#define DIME 	10
#define NICKEL	5

int main(){
	int amount;
	int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
	cout<<"Enter the amount: ";
	cin>>amount;

	quarters = amount / QUARTER;
	amount = amount % QUARTER;
	dimes = amount / DIME;
	amount = amount % DIME;
	nickels = amount / NICKEL;
	amount = amount % NICKEL;
	pennies = amount;

	cout<<"Quarters: "<<quarters<<", Dimes: "<<dimes<<", Nickels: "<<nickels<<" and Pennies: "<<amount<<endl;

	cout<<"Numbers of coins: "<<quarters + dimes + nickels + amount<<endl;

	return 0;

}
