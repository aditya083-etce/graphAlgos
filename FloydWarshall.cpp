#include<bits/stdc++.h>
using namespace std;

// -1 -> no path

void shortest_distanceFW(vector<vector<int>>&Dis){
    int V = Dis.size();
    for(int k = 0; k<V; k++){
        for(int s = 0; s<V; s++){
            for(int d = 0; d<V; d++){
                if (Dis[s][k] != -1 && Dis[k][d] != -1){
                    if (Dis[s][d] == -1){
                        Dis[s][d] = Dis[s][k] + Dis[k][d];
                    }else{
                        Dis[s][d] = min(Dis[s][d], Dis[s][k] + Dis[k][d]);
                    }
                } 
            }
        }
    }
}

int main() {
    // n -> vertices
    // m -> edges
    int n, m;
    cin >> n >> m;

    // intialization of distance or weighted arr where rows is src and cols is dest
    // no self edge

    vector<vector<int>> adjMat(n, vector<int> (n, -1));

    for(int u = 0; u<n; u++){
        for(int v = 0; v<n; v++){
            if (u == v) adjMat[u][v] = 0;
        }
    }

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjMat[u][v] = w;
        adjMat[v][u] = w;
    }

    shortest_distanceFW(adjMat);

    for(int u = 0; u<n; u++){
        for(int v = 0; v<n; v++){
            cout << adjMat[u][v] << " ";
        }
        cout << endl;
    }

	return 0;
}
