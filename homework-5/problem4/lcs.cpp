#include <iostream>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;

int main(){
	char first[20], second[20];
	cout<<"\nEnter the first subsequence:";
	cin>>first;
	cout<<"\nEnter the second subsequence:";
	cin>>second;

	int len1 = strlen(first);
	int len2 = strlen(second);

	int c[len1][len2], b[len1][len2];

	for(int i=0; i<len1; i++){
		c[i][0] = 0;
		b[i][0] = 0;
	}

	for(int j=0; j<len2; j++){
		c[0][j] = 0;
		b[0][j] = 0;
	}

	for(int i=1; i<=len1; i++){
		for(int j=1; j<=len2; j++){
			if(first[i-1] == second[j-1]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 99;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 100;
			}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = 101;
			}
		}
	}

	int i = len1, j = len2;
	vector<char> charList;
	while(i!=0 && j!=0){
		switch(b[i][j]){
			case 99:{
				charList.emplace(charList.begin(),first[i-1]);
				i--;
				j--;
			}
			break;
			
			case 100:{
				i--;
			}
			break;

			case 101:{
				j--;
			}
			break;
		}
	}
	cout<<"\nLeast common subsequence is:";
	int count=0;
	for (int i = 0; i < charList.size(); i++){
		cout << charList[i];
		count++;
	}
        
    cout<<"\nSize of subsequence: "<<count<<endl;	
    return 0;
}
