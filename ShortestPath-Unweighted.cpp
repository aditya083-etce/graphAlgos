#include<bits/stdc++.h>
using namespace std;
// non weighted 

vector<int> bfs(int V, int S, vector<int> adjList[])
{
    vector<int> Dis(V, INT_MAX);
    Dis[S] = 0;
    vector<bool> inclu(V, false);
    queue<int> q;
    
    q.push(S);
    
    while(!q.empty()) {
        int at = q.front();
        q.pop();
        inclu[at] = true;

        for(int to: adjList[at]) {
            if (!inclu[to] and Dis[at] + 1 < Dis[to]) {
                Dis[to] = Dis[at] + 1;
                q.push(to);
            }
        }
    }
    return Dis;
}

int main(){
    // n -> vertices   m -> edges
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n];

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int startNode;
    cin >> startNode;

    vector<int> path = bfs(n, startNode, adjList);

    for(int i = 0; i<n; i++){
        cout << "Distance from " << startNode <<" to " << i <<" node: " << path[i] << endl;
    }

    return 0;
}