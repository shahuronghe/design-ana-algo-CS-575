#include<iostream>
using namespace std;

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void coolSort(int *arr, int n, int *hseq, int h){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++)
			for(int k = j; k < n; k = k + hseq[i]){
				int key = arr[k];
				int l = k - hseq[i];
				while(l >= 0 && arr[l] > key){
					arr[l + hseq[i]] = arr[l];
					l = l - hseq[i];
				}
				arr[l + hseq[i]] = key;
			}
	}	
}

int main(){

	int n,h;
	cout << "Enter array size: ";
	cin >> n;
	
	int *arr = new int[n];
	
	cout<< "Enter array elements: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout<< "Enter H size: ";
	cin>>h;
	
	int *hseq = new int[h];
	
	cout<<"Enter H elements: ";
	for(int i =0; i < h; i++)
		cin>>hseq[i];

	coolSort(arr, n, hseq, h);

	printArray(arr,n);
}
