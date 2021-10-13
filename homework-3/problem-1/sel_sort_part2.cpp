#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size, int k);

int main(){
	int n, k;
	cout << "Enter array size: ";
	cin >> n;
	int *arr = new int[n];
	cout << "Enter array elements: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Enter the value for 'k': ";
	cin >> k;
	SelectionSort(arr, n, k);
	for(int i = 0; i < k; i++)
		cout << arr[i]<<" ";
	cout <<endl;
}

void SelectionSort(int arr[], int size, int k){
	for(int i = 0; i < k; i++){
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
