#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0
// Negative cycle detection

/* =================================== =========
BELLMAN FORD ALGORITHIM

    1. Initialise Dis array, Dis[S] = 0 
    2. Iterate V - 1 times (Relax the edges)
    3. Visit the edges and if Dis[u] + w < Dis[v] then update Dis[v] = Dis[u] + w
    4. coming out from the loop iterate agi througn edgeList if  Dis[u] + w < Dis[v] -> -ve edge cycle is detected
        if it is false return dis vection which contains the Shortest path

Time Complexity - O(V*E)
======================================= =========*/

vector<int> Dis;
bool ShortestPathBellmanFord(int V, int S, vector<vector<int>>edgeList){
    Dis.resize(V, INT_MAX);
    Dis[S] = 0;
    // Relax edges V - 1 times
    V = V - 1;
    while(V--)
    {
        for(auto vec: edgeList)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            if(Dis[u] != INT_MAX and Dis[u] + w < Dis[v]){
                Dis[v] = Dis[u] + w;
            }
        }
    }
        
    for(auto vec: edgeList)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        
        if(Dis[u] != INT_MAX and Dis[u] + w < Dis[v]){
            return 1;
        }
    }
    return 0;
}

int main(){
    // n -> vertices   m -> edges
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edgeList;
    for(int i = 0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
    }

    int startNode;
    cin >> startNode;

    if (ShortestPathBellmanFord(n, startNode, edgeList)){
        cout << "Negative edge cycle detected" <<endl;
    }else{
        for(int path: Dis){
            cout << path << " ";
        }
    }

    return 0;
}
