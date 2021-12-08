#include <iostream>
using namespace std;


int notPointN(int arr[], int len, int k){
	for(int i = 0; i < len; i++){
		if(arr[i] == k)
			return 0;
		if(i == len - 1)
			return -1;
	}
	return -1;
}

int findMinOfAllPoints(int arr[], int len, int n[]){
	int min = 999;
	int minIndex;

	for(int i = 0; i < len; i++){
		if(notPointN(n, len, i) && (arr[i] < min)){
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main(){
	int len;

	cout<<"\nEnter the number of vertices in the graph: ";
	cin>>len;

	int n[len] = { -1 }, pointer[len] = { 0 }, arr[len], minIndex, array[len][len];
	n[0] = 0;

	cout<<"\nEnter the values of graph edges: ";

	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			cout<<"\nEnter the edge between "<<(i+1)<<" - "<<(j+1);
			cin>>array[i][j];
		}
	}

	for(int i = 0; i < len; i++)
		arr[i] = array[0][i];

	int minPoint;
	for(int i = 0; i < len; i++){
		minIndex = findMinOfAllPoints(arr, len, n);

		if(i == 0){
			cout<<"\t";
			for(int j = 1; j < len; j++)
				cout<<j;
		}

		cout<<"\n\n"<<i;
		
		for(int j = 0; j < len; j++){
			if(notPointN(n, len, j))
				cout<<arr[j]<<","<<pointer[j];
			 else 
				cout<<"\t";
			
		}

		n[i + 1] = minIndex;
		minPoint = minIndex;

		for(int j = 0; j < len; j++){
			if(notPointN(n, len, j)){
				if(arr[j] > (arr[minPoint] + array[minPoint][j])){
					arr[j] = arr[minPoint] + array[minPoint][j];
					pointer[j] = minPoint;
				}
			} else
				continue;
		}
	}
	return 0;
}
