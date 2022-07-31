// Cycle Detection in Undirected graph --- BFS and DFS using parent and UNION FIND

// using BFS
bool detectCycleBFS1(int V, vector<int> adj[]) {
        
    queue<pair<int, int>> Q;
    vector<bool> visited(V+1, false);
    
    for(int i = 1; i <= V; i++) {
        
        if(!visited[i]) {
            
            Q.push({i, -1});
            visited[i] = true;
            
            while(!Q.empty()) {
                
                int at = Q.front().first;
                int pt = Q.front().second;

                cout << "(" << at <<"," << pt <<")" <<",";
                
                for(int to : adj[at]) {
                    
                    if(!visited[to]) {
                        Q.push({to, at});
                        visited[to] = true;
                    } else if(to != pt) {
                        // visited but not parent (pt)
                        return true;
                    }
                }
                
                Q.pop();
            }
        }
    }
    
    return false;
}

bool detectCycleBFS2(int V, vector<int> adj[]) {
    queue<int> Q;
    vector<bool> visited(V+1, false);
    vector<int> parent(V+1, -1);

    for(int i = 1; i <= V; i++){

        if (!visited[i]) {
            
            Q.push(i);
            visited[i] = true;

            while (!Q.empty())
            {
                int at = Q.front();

                for(int to: adj[at]) {

                    if(!visited[to]) {
                        Q.push(to);
                        parent[to] = at;
                        visited[to] = true;
                    } else if (to != parent[at]) {
                        // visited but not parent
                        return true;
                    }
                }
                
                Q.pop();
            }
        }
        return false;
    }
}

// using DFS
bool DFS(int at, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[at] = true;
    bool ans = false;

    for(int to: adj[at]) {
        if (!visited[to]) {
            ans = (ans | DFS(to, at, adj, visited));
        }else if (to != parent) {
            return true;
        }
    }

    return ans;
}

bool detectCycleDFS(int V, vector<int> &adj[]) 
{
    vector<bool> visited(V+1, false);
    for(int i = 1; i<=V; i++) {
        if(!visited[i] and DFS(i, -1, adj, visited)) {
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
        adj[v].push_back(u);
    }

    if (detectCycleBFS1(n, adj)){
        cout << "Detected" <<endl;
    }else{
        cout << " Not Detected" <<endl;
    }

    return 0;
}


