#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//main function
int main(){
	int c, k, amount;
	//taking user inputs
	cout<<"Enter the value of c: ";
	cin>>c;

	cout<<"Enter the value of power: ";
	cin>>k;

	cout<<"Enter the amount: ";
	cin>>amount;

	int denominations[k + 1];
	int quantityPerCoin[k + 1];

	//creating denomination array of power c to i.
	for(int i = 0; i <= k; i++){
		denominations[i] = (int) pow(c,i);
	}

	//calculating coin count each
	for(int i = k; i >= 0; i--){
		quantityPerCoin[i] = amount / denominations[i];
		amount = amount % denominations[i];
	}

	//displaying quantity of coins.
	for(int i = k; i >= 0; i--){
		cout<<"Number of Coins of "<<denominations[i]<<": "<<quantityPerCoin[i]<<endl;
	}

	return 0;
}
