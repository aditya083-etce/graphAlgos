#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0 // directed
// Dijkstra fails for negative cycle and negative edge

/* =================================== =========
DIJKSTRA ALGORITHIM

    1. Initialise Dis array, INCLU boolean array and take a PQ (min heap) push  ({Dis[S], S}) 
    2. Take the min pair from PQ, mark it true in INCLU, pop it from PQ
    3. Visit the neighbours and find if the neighbour node is already marked True or not
        if marked False and Dis[parent] + neighbour.wt < Dis[neighbour] then update the Dis[neighbour] = Dis[parent] + neighbour.wt
    4. Push the pair ({Dis[neighbour], neighbour})
    5. Return Dis witch contains the path from S to all the Dest (as index)

Time Complexity - O((V + E) log V) with fibonacci heap
======================================= =========*/

vector <int> ShortestPathDijkstra(int V, int S, vector<vector<int>> adjList[])
{
    vector<int> Dis(V, INT_MAX);
    Dis[S] = 0;
    vector<bool> INCLU(V, false);
    priority_queue < pair<int, int> , vector< pair<int, int> > , greater< pair<int, int> > > PQ;  

    PQ.push({Dis[S], S});

    while (!PQ.empty()){
        int at = PQ.top().second;
        int d = PQ.top().first;
        INCLU[at] = true;
        PQ.pop();
        
        for(auto ngbrs: adjList[at]){
            int to = ngbrs[0];
            int wt = ngbrs[1];

            if (!INCLU[to] and d + wt < Dis[to]){
                Dis[to] = d + wt;
                PQ.push({Dis[to], to});
            }
        }
    }
    return Dis;
}

int main(){
    // n -> vertices   m -> edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList[n];

    for(int i = 0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;

        adjList[u].push_back({v, wt});
    }

    int startNode;
    cin >> startNode;

    vector<int> path = ShortestPathDijkstra(n, startNode, adjList);

    for(int i = 0; i<n; i++){
        cout << "Distance from " << startNode <<" to " << i <<" node: " << path[i] << endl;
    }

    return 0;
}