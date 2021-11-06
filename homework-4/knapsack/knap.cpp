#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//function to calculate the maximum profit using knapsack algo
void calculateKnapsack(int w, int weights[], int values[], int n){
	int k[n + 1][w + 1];

	//building k on the basis of weights and values.
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <=w; j++){
			if(i == 0 || j == 0)
				k[i][j] = 0;
			else if (weights[i - 1] <= j)
				k[i][j] = max(values[i - 1] + k[i - 1][j - weights[i - 1]], k[i - 1][j]);
			else
				k[i][j] = k[i - 1][j];
		}
	}

	//maximum profit has been calculated
	int res = k[n][w];
	cout<<"Maximum Profit: "<<res<<endl;
	int temp = w;

	//display weights and values used for calculating maximum profit using knapsack algo
	for(int i = n; i > 0 && res > 0; i--){
		if (res == k[i - 1][temp])
			continue;

		else{
			cout<<"Weight: "<<weights[i - 1]<<" - Value: "<<values[i - 1]<<endl;
			res = res - values[i - 1];
			temp = temp - weights[i - 1];
		}
	}
}

//main function
int main(){
	int values[] = {3, 4, 5, 6};
	int weights[] = {2, 3, 4, 5};
	int w = 5;
	int n = sizeof(values)/sizeof(values[0]);

	calculateKnapsack(w, weights, values, n);

	return 0;
}
