#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            // Found a node in recursion stack → cycle
            return true;
        }
    }

    recStack[node] = false; // Backtrack
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1); // 1-based indexing
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<bool> visited(N + 1, false);
    vector<bool> recStack(N + 1, false);

    bool cycle = false;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}