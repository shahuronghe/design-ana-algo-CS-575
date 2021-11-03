#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int change(int amount){
	cout<<"amount: "<<amount<<endl;
	if(amount < 0)
		return 1000000;
	
	if(amount == 0)
		return 0;
	else
		return 1 + min({change(amount - 1), change(amount - 5), change(amount - 10)});
}

int main(){
	int amount;
	cout<<"Enter the amount: ";
	cin>>amount;

	int answer = change(amount);
	cout<<"the answer is "<<answer<<endl;


	return 0;
}
