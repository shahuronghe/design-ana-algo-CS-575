#include<iostream>
using namespace std;

bool search(int arr[], int min, int max);

int main(){
	int num;
	cout << "Enter array size: ";
	cin >> num;
	int *arr = new int[num];
	cout << "Enter array elements: ";
	for(int i = 0; i < num; i++)
		cin >> arr[i];

	if(search(arr, 0, num-1))
		printf("Found!\n");
	else
		printf("Not found\n");

	return 0;
}

bool search(int arr[], int min, int max){
	int n = max - min;
	if(n == 0)
		return true;
	int m = min + (n/2);
	if(m < arr[m])
		return search(arr, min, m);

	if(m > arr[m])
		return search(arr, m+1, max);
	return false;
}
