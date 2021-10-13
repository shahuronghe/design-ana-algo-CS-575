#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size);

int main(){
	int n;
	cout << "Enter array size: ";
	cin >> n;
	int *arr = new int[n];
	cout<< "Enter array elements: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	SelectionSort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i]<<" ";
	cout <<endl;
}

void SelectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}		
	}
}
