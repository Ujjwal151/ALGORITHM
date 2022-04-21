//DP 7. Longest Increasing Subsequences 
// LIS by sorting and LCS
#include<bits/stdc++.h>
using namespace std;

void LCS(int X[], int Y[], int m, int n){
	char b[m+1][n+1];
	int c[m+1][n+1];
	for(int i = 0; i<=m; i++)  c[i][0] = 0;
	for(int j = 0; j<=n; j++)  c[0][j] = 0;
	for(int i= 1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			if(X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 'C';
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 'U';
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 'L';
			}
		}
	}
	cout<<"LIS-Length : "<<c[m][n]<<"\n";
//------------------------------------------
	int i = m, j = n;
	vector<int> v;
	while(i && j){
		if(b[i][j] == 'C'){
			v.push_back(X[i-1]);
			i--,j--;
		}
		else if(b[i][j] == 'U') i--;
		else j--;
	}
	reverse(v.begin(), v.end());
	cout<<"LIS is = ";
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	cout<<"\n";
}

int main()
{
	int arr[] = {50,4,60,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int arr1[n];
	for(int i = 0; i<n; i++){
		arr1[i] = arr[i];
	}
	sort(arr1, arr1+n);
	LCS(arr,arr1,n,n);
}
