#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0

/* =================================== =========
Detect Cycle Of Undirected Graph ( UNION FIND )

    1. Intialize the disjoint set array
    2. Find Ansolute Parent
    3. Union operation (if absoute roots are not same)
        if absolute roots are same the cycle found 

Time Complexity - O(E * V)
======================================= =========*/

int parent[100000];
int Sz[100000]; // rank

void initialize(int n) {
    for(int i = 1; i<=n; i++) {
        parent[i] = i;
        Sz[i] = 1;
    }
}

int findParen(int node) {
    if (node == parent[node]) return node;
    
    return parent[node] = findParen(parent[node]);
}

void unionNodes(int u, int v) {
    u = findParen(u);
    v = findParen(v);
    
    if (Sz[u] <= Sz[v]){
        parent[u] = v;
        Sz[v] += Sz[u]; 
    } else {
        parent[v] = u;
        Sz[u] += Sz[v];
    }
}

bool detectCycle(int V, vector<pair<int, int>> edgeList){
    initialize(V);

    for(auto edge: edgeList){
        int p1 = findParen(edge.first);
        int p2 = findParen(edge.second);
        
        if (p1 == p2) return true;

        unionNode(p1, p2);
    }
    return false;
}

int main(){
    // n -> vertices   m -> edges
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edgeList;

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;

        edgeList.push_back({u, v});
    }

    if (detectCycle(n, edgeList)){
        cout << "Detected" <<endl;
    }else{
        cout << " Not Detected" <<endl;
    }

    return 0;
}