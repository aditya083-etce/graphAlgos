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