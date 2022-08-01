#include<bits/stdc++.h>
using namespace std;
// Here the vertices starts from 0

/* =================================== =========
KOSARAJU ALGORITHIM (DFS)

    1. Apply DFS with stack
    2. Reverse the edges
    3. Pop the node one by one check if visited or not and apply DFS
        IF the neighbour is already visited the SSC is found

Time Complexity - O(V + E)
======================================= =========*/

stack<int> st;
vector<bool> visited;

void DFSwithStack(int at, vector<int> adjList[]){
    visited[at] = true;
    for(int to: adjList[at]){
        if (!visited[to]){
            DFSwithStack(to, adjList);
        }
    }
    st.push(at);
}

void DFS(int at, vector<int> adjList[], vector<int> &comp){
    visited[at] = true;
    comp.push_back(at);
    for(int to: adjList[at]){
        if (!visited[to]){
            DFS(to, adjList, comp);
        }
    }
}

int kosaraju(int V, vector<int> adjList[])
{
    visited.resize(V, false);

    for(int i = 0; i<V; i++){
        if (!visited[i]){
            DFSwithStack(i, adjList);
        }
    }

    // Reverse the edges
    vector<int> adjList2[V];
    for(int at = 0; at<V; at++){
        visited[at] = false;
        for(auto to: adjList[at]){
            adjList2[to].push_back(at);
        }
    }

    int cnt = 0;
    vector<vector<int>> SSC;

    while (!st.empty())
    {
        int at = st.top();
        st.pop();

        if(!visited[at]){
            vector<int> comp;
            DFS(at, adjList2, comp);
            SSC.push_back(comp);
            cnt++;
        }
    }

    for(auto vec: SSC){
        for(int val: vec){
            cout << val << " ";
        }
        cout<<endl;
    }

    return cnt;
}

int main(){
    // n -> vertices   m -> edges
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n];

    for(int i = 0; i<m; i++){
        int u, v, wt;
        cin >> u >> v;

        adjList[u].push_back(v);
    }

    int k = kosaraju(n, adjList);
    cout << "No of Strongly Connected Components: " << k <<endl;

    return 0;
}