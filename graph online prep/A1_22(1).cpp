#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // reverse_graph[B] = list of A's (prerequisites of B)
    vector<vector<int>> reverse_graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        reverse_graph[B].push_back(A);
    }
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int C;
        cin >> C;
        
        // BFS to count all ancestors of C
        vector<bool> visited(N + 1, false);
        queue<int> q;
        
        q.push(C);
        visited[C] = true;
        int count = 0;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            
            for (int prereq : reverse_graph[course]) {
                if (!visited[prereq]) {
                    visited[prereq] = true;
                    count++;
                    q.push(prereq);
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}