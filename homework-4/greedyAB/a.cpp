#include<iostream>
using namespace std;

//decalaring constants
#define QUARTER 25
#define DIME 	10
#define NICKEL	5

//main function
int main(){
	int amount;

	//initializing coins count as 0
	int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
	cout<<"Enter the amount: ";
	cin>>amount;

	//calculating all coin count in decending order using modulus operator
	quarters = amount / QUARTER;
	amount = amount % QUARTER;
	dimes = amount / DIME;
	amount = amount % DIME;
	nickels = amount / NICKEL;
	amount = amount % NICKEL;
	pennies = amount;

	cout<<"Quarters: "<<quarters<<", Dimes: "<<dimes<<", Nickels: "<<nickels<<" and Pennies: "<<pennies<<endl;

	cout<<"Numbers of coins: "<<quarters + dimes + nickels + pennies<<endl;

	return 0;
}
