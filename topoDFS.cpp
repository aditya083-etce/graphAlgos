#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<bool> visited;

void dfs(int at, vector<int> adj[])
{
	visited[at] = true;
	for(int to: adj[at]) {
		if (!visited[to]) dfs(to, adj);
	}

	st.push(at);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

	visited.resize(n, false);

	for(int i = 0; i<n; i++){
		if (!visited[i]) dfs(i, adj);
	}

	vector<int> ans;
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

    cout << "TOPOLOGICAL SORT : ";
    for(int i: ans){
        cout << i << ", ";
    }
	return 0;
}
