#include <bits/stdc++.h>
using namespace std;

// DFS to visit all reachable nodes
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

// Function to check connectivity
bool isConnected(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    
    // Build adjacency list
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<bool> visited(V, false);
    
    // Start DFS from node 0
    dfs(0, adj, visited);

    // Check if all nodes were visited
    for(int i = 0; i < V; i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for(int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1];

    if(isConnected(V, edges)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}