//DP 7. Longest Increasing Subsequences
#include<bits/stdc++.h>
using namespace std;

int LIS_FUNCTION(int arr[], int n)
{
	int LIS[n];
	for(int i = 0; i<n; i++)
		LIS[i] = 1;
	for(int i = 1; i<n; i++){
		for(int j = 0; j<=i-1; j++){
			if(arr[i]>arr[j] && LIS[i]<=LIS[j]){
				LIS[i] = LIS[j]+1;
			}
		}
	}
	return *max_element(LIS,LIS+n);
}

int main()
{
	int arr[] = {50,4,60,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"LIS item = "<<LIS_FUNCTION(arr,n);
}
