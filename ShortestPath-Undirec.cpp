#include<bits/stdc++.h>
using namespace std;

int ShortestPathSrcToDest(int V, vector<int> adjList[], int src, int dest)
{
    vector<bool> visited(V, false);
    queue<int> q;

    int level = 1;
    q.push(src);
    visited[src] = true; 

    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {
            int at = q.front();
            q.pop();
            if (at == dest) return level - 1;

            for(int to: adjList[at]) {
                if (!visited[to]) {
                    q.push(to);
                    visited[to] = true;
                }
            }
            level++;
        }
    }

    return -1;
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

    int src, dest;
    cin >> src >> dest;
    
    cout << ShortestPathSrcToDest(n, adjList, src, dest) << endl;

    return 0;
}