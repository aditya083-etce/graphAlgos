bool detectCycle(int at, vector<int> adj[], vector<int> &color) {
    color[at] = 1;

    for(int to: adj[at]){
        if(color[to] == 0){
            if (detectCycle(to, adj, color)){
                return true;
            }
        }else if (color[to] == 1){
            return true;
        }
    }

    color[at] = 2;
    return false;
}

bool graphColoringCycleDetection(int V, vector<int> adj[]){
    // 0 -> not visited   1 -> visited (in rs stack)  2-> visited + processed (not in rs stack)
    vector<int> color(V, 0); // thick color [1] as rs

    for(int i = 0; i<V; i++){
        if (color[i] == 0){
            if (detectCycle(i, adj, color)){
                return true;
            }
        }
    }
    return false;
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    if (graphColoringCycleDetection(n, adj)){
        cout << "Detected" <<endl;
    }else{
        cout << " Not Detected" <<endl;
    }

    return 0;
}