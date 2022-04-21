//DP 6. LOngest Common Subsequences
#include<bits/stdc++.h>
using namespace std;
void LCS_Length(string X, string Y){
	int m = X.size();
    int n = Y.size();
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
	cout<<"LCS-Length : "<<c[m][n]<<"\n";
//--------------------------------------------------------
	int i = m, j = n;
	string str;
	while(i && j){
		if(b[i][j] == 'C'){
			str.push_back(X[i-1]);
			i--,j--;
		}
		else if(b[i][j] == 'U') i--;
		else j--;
	}
	reverse(str.begin(), str.end());
	cout<<"LCS is = "<<str;
}

int main()
{
	string X = "ABCDEFG";
	string Y = "XZACKDFWGH";
	LCS_Length(X,Y);
}
