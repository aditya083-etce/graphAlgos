// Cycle Detection in Directed graph --- DFS using backedge (recursion stack) , GRAPH colouring, KHAN'S ALGORITHM

// using DFS
vector<bool> visited;
vectot<bool> rs;

bool DFS(int at, vector<int> adj[]) {
    visited[at] = true;
    bool ans = false;
    
    rs[at] = true;

    for(int to: adj[at]) {
        if (!visited[to]) {
            ans = (ans | DFS(to, adj));
        }else if (rs[to]) {
            return true;
        }
    }

    rs[at] = false;

    return ans;
}

bool detectCycleDFS(int V, vector<int> &adj[]) 
{
    visited.resize(V+1, false);
    rs.resize(V+1, false)
    for(int i = 1; i<=V; i++) {
        if(!visited[i] and DFS(i, adj)) {
            return true;
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

    if (detectCycleDFS(n, adj)){
        cout << "Detected" <<endl;
    }else{
        cout << " Not Detected" <<endl;
    }

    return 0;
}


