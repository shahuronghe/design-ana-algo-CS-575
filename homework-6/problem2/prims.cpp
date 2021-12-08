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

int main(){

	int len;
	cout<<"\nEnter the number of vertices for the graph:";
	cin>>len;

	int n[len] = { -1 }, array[len][len], a[len][2], min;
	n[0] = 0;

	cout<<"\nEnter the values of graph edges: ";

	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			cout<<"\nEnter edge between "<<(i + 1)<<" - "<<(j + 1);
			cin>>array[i][j];
		}
	}

	cout<<"\nSet of the minimum edges is as follows: ";
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			if(n[j] != -1){
				min = 999;
				for(int k = 0; k < len; k++){
					if(notPointN(n, len, k)){
						if(min > array[k][n[j]]){
							min = array[k][n[j]];
							a[i][0] = k;
							a[i][1] = n[j];
						}
					}
				}
			}
		}
		n[i] = a[i][0];
		cout<<"\n("<<a[i][0]<<", "<<a[i][1]<<")";
	}
	cout<<endl;
	return 0;
}

