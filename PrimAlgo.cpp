#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0

/* =================================== =========
PRIM ALGORITHIM

    1. Initialise Key array, MST boolean array and take a set push all ({Key[i], i}) pair in it
    2. Take the min pair from set, mark it true in MST, increase cost and erase it from Set
    3. Visit the neighbours and find if the neighbour node is already marked True or not
        if marked False then update the Set of that node and Key [node] with min of previous wt and curr wt from from adj[at] 

Time Complexity - O((V + E) log V)
======================================= =========*/

int PrimCostMST(int V, vector<vector<int>> adjList[])
{
    vector<int> Key(V, INT_MAX);
    vector<bool> MST(V, false);
    set< pair<int, int> > Set;

    Key[0] = 0; // starting point
    for(int i = 0; i<V; i++){
        Set.insert({Key[i], i});
    }

    int cost = 0;
    while (!Set.empty()){
        auto mn = Set.begin();
        int key = mn->first;
        int at = mn->second;

        MST[at] = true;
        cost += key;
        Set.erase(mn);

        for(auto ngbrs: adjList[at]){
            int to = ngbrs[0];
            int wt = ngbrs[1];

            if (!MST[to] and Key[to] > wt){
                Set.erase(Set.find({Key[to], to}));
                Key[to] = wt;
                Set.insert({Key[to], to});
            }
        }
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

    int cost = PrimCostMST(n, adjList);
    cout<<"Minimum Cost:" << cost << endl;

    return 0;
}