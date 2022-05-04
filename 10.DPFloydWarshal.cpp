// Floyd Warshal Algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int INF = 1e9+10;
int dis[N][N];

int main(){
	for(int i = 0; i<N; i++)
		for(int j= 0; j<N; j++){
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}

	int n,e;
	cin>>n>>e;
	for(int i = 0; i<e; i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		dis[x][y] = wt;
	}

	for(int k = 1; k<=n; ++k)
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=n; j++)
				if(dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	


	for(int i = 1; i<=n; i++){
		for(int j= 1; j<=n; j++){
			if(dis[i][j] == INF)
				cout<<"I ";
			else cout<< dis[i][j]<<" ";
		}
		cout<<"\n";
	}

}