#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0

/* =================================== =========
Detect Cycle Of Undirected Graph ( UNION FIND )

    1. Intialize the disjoint set array
    2. Find Ansolute Root
    3. Union operation (if absoute roots are not same)
        if absolute roots are same the cycle found 

Time Complexity - O(E * V)
======================================= =========*/

vector<int> PARENT; // Disjoint set array (parent)

vector<int> Sz; // Size or Rank

void initialize(int n)
{
    PARENT.resize(n);
    Sz.resize(n, 1);
    for(int i = 0; i<n; i++){
        PARENT[i] = i;
    }
}

int findRoot(int v){
    if (v == PARENT[v]){
        return v;
    }
    return PARENT[v] = findRoot(PARENT[v]);
}


void UnionRoot(int x, int y)
{
    int g1 = findRoot(x);
    int g2 = findRoot(y);

    if (g1 == g2){
        return;
    }

    if (Sz[g2] <= Sz[g1]){
        PARENT[g2] = g1;
        Sz[g1] += Sz[g2];
    }else{
        PARENT[g1] = g2;
        Sz[g2] += Sz[g1];
    }
}

bool detectCycle(int V, vector<pair<int, int>> edgeList){

    initialize(V);

    for(auto edge: edgeList){
        int p1 = findRoot(edge.first);
        int p2 = findRoot(edge.second);
        
        if (p1 == p2) return true;

        UnionRoot(p1, p2);
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