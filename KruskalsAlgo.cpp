#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 1

/* =================================== =========
KRUSKALS ALGORITHIM ( UNION FIND )

    1. Sort the edges (in order of their weighte)
    2. Pick Smallest edge
    3. Check if the edge forms a cycle in MST
        if cycle is not formed -----> include the edge
        otherwise ------> disaed the edge 

Time Complexity - O(ElogE + ElogV)
======================================= =========*/

#include<bits/stdc++.h>
using namespace std;

vector<int> PARENT; 
vector<int> Sz;

void initialize(int v)
{
    PARENT[v] = v;
    Sz[v] = 1;
}

int findRoot(int v){
    if (v == PARENT[v]) return v;
    return PARENT[v] = findRoot(PARENT[v]);
}


void UnionRoot(int x, int y)
{
    int g1 = findRoot(x);
    int g2 = findRoot(y);

    if (g1 == g2) return;

    if (Sz[g2] <= Sz[g1]){
        PARENT[g2] = g1;
        Sz[g1] += Sz[g2];
    }else{
        PARENT[g1] = g2;
        Sz[g2] += Sz[g1];
    }
}

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int KursalCostMST(int V, vector<vector<int>> adjList[]){
    PARENT.resize(V);
    Sz.resize(V);
    for(int i = 0; i<V; i++){
        initialize(i);
    }

    // Converting adjList to edgeList
    vector<vector<int>> edgeList;
    for(int u = 0; u<V; u++){
        for(auto vec: adjList[u]){
            int v = vec[0], w = vec[1];
            edgeList.push_back({u, v, w});
        }
    }

    sort(edgeList.begin(), edgeList.end(), compare);

    int cost = 0, edgecnt = 0;

    for(auto edge: edgeList) {
        if (edgecnt > V-1) break;
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        //Cycle found
        if (findRoot(u) == findRoot(v)) continue;

        UnionRoot(u, v);
        cost += w;
        edgecnt++;
        cout << u << " " << v << endl;
    }
    return cost;
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
        adjList[v].push_back({u, wt});
    }

    int cost = KrusalCostMST(n, adjList);
    cout<<"Minimum Cost: " << cost << endl;

    return 0;
}