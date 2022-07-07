#include<bits/stdc++.h>
using namespace std;

vector<int> khanAlgo(int V,  vector<int> adj[])
{
    vector<int> indeg(V, 0);
	for(int i = 0; i<V; i++){
		for(int j: adj[i]){
			indeg[j]++;
		}
	}

	queue<int> Q;
    vector<int> res;

	for(int i = 0; i<V; i++){
		if (indeg[i] == 0) Q.push(i);
	}

	int count = 0;
	while (!Q.empty())
	{
		int at = Q.front();
		Q.pop();
		res.push_back(at);

		for(int to: adj[at]){
			indeg[to]--;
			if (indeg[to] == 0){
				Q.push(to);
			}
		}
		count++;
	}

	if (count != V){
		cout << "GRAPH IS NOT DAG" <<endl;
        return {};
	}

	return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n+1];

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        
        adjList[u].push_back(v);
    }

	vector<int> ans = khanAlgo(n, adjList);

    cout << "TOPOLOGICAL SORT : ";
    for(int i: ans){
        cout << i << ", ";
    }
	return 0;
}
