// MINIMUM SPANNING TREE - KRUSKAL ALGO
#include<bits/stdc++.h>
using namespace std;

int MSTKruskal(int V,  vector<pair<int, int>> adj[])
{
	vector<pair<int,pair<int,int>>> edge;
	for(int i = 0; i<=n; i++){
		for(auto x: adj[i]){
			edge.push_back({{x.second}, {i, x.first}});
		}
	}

	sort(edge.begin(), edge.end());

	int 
}

int main() {
	// n -> no of vertices  m -> no of edges
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adjList[n+1];

    for(int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;
        
        adjList[u].push_back{v, w});
		adjList[v].push_back{u, w});
    }

	cout << MSTKruskal(n, adjList) << endl;
	return 0;
}
