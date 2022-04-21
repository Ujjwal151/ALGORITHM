//8.DP Dijkstra 
#include<bits/stdc++.h>
using namespace std;
const int N = 4;//Number of nodes
const int INF = 1e9+10;
vector<pair<int,int> > g[N];
vector<int> visited(N, 0);
vector<int> dist(N, INF);
set<pair<int,int> > st;

void dijkstra(int source){
	
	st.insert({0,source});
	dist[source] = 0;
	while(st.size() > 0){
		auto node = *st.begin();
		int v = node.second;
		int distance = node.first;
		st.erase(st.begin());
		if(visited[v]) continue;
		visited[v] = 1;

		for(auto child : g[v]){
			int child_v = child.first;
			int wt = child.second;
			if(dist[v] + wt < dist[child_v]){
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}
}

int main()
{
	int m; //Number of edges using Adjacency list
	cin>>m;
	for(int i = 0; i<m; i++)
	{
		int x, y, wt;
		cin>>x>>y>>wt;
		g[x].push_back({y,wt});
	}

	dijkstra(0); //Passing Source

	for(int i = 0; i<N; i++){
		cout<<"Distance of 0 to "<<i<<" = "<<dist[i]<<"\n";
	}

}

/*
INPUT FILE
6
0 1 3
0 2 4
0 3 9
1 2 2
1 3 5
3 2 1
*/