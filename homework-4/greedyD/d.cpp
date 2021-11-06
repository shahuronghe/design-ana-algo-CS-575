#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//function to make changes based on the amount provided.
int change(int amount, int coins[], int len){
	//return 0 when amount amount reaches to 0
	if(amount == 0)
		return 0;

	// recursively calculate number of coins.
	for(int i = len; i > 0; i--){
		int value = coins[i - 1];
		if(amount >= value){
			cout<<value<<" ";
			return 1 + change(amount - value, coins, len);
		}
	}
	cout<<"Unable to make change..."<<endl;
	cout<<"Cents remaining: "<<amount<<endl;
	return 0;
}

//main function
int main(){
	//initialized coin denominations
	int coins[] = {1, 5, 10, 25};
	int len = sizeof(coins)/sizeof(coins[0]);

	//user input
	int amount;
	cout<<"Enter the amount: ";
	cin>>amount;

	int answer = change(amount, coins, len);
	cout<<endl<<"Total Coins: "<<answer<<endl;


	return 0;
}
