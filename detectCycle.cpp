// // using union find;

// vector<int> R;

// void Union(int x, int y)
// {
//     int g1 = Find(x);
//     int g2 = Find(y);

//     if (g1 == g2) return;
    
// }

bool detectCycle(int V, vector<int> adj[]) {
        
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
                        
                        return true;
                    }
                }
                
                Q.pop();
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

    if (detectCycle(n, adj)){
        cout << "Detected" <<endl;
    }else{
        cout << " Not Detected" <<endl;
    }

    return 0;
}


