vector<vector<int>> edgeList;
int ConvertAdjtoEdj(int V, vector<vector<int>> adj[]) {
    // Converting adjacency list into edge list.
    for(int u = 0; u < V; u++) {

        for(auto vec : adj[u]) {
            
            int v = vec[0], w = vec[1];
            
            edgeList.push_back({u, v, w});
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n];

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    ConvertAdjtoEdj(n, adj);

    for(int i = 0; i<m; i++){
        cout << edgeList[i][0] << edgeList[i][1] <<  edgeList[i][2] << endl;
    }
    return 0;
}