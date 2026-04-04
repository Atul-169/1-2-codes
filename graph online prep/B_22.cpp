#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    // Find starting position S
    int startR = -1, startC = -1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == 'S') {
                startR = i;
                startC = j;
            }

    // BFS
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;

    q.push({startR, startC});
    visited[startR][startC] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int exitCount = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Boundary check
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // Obstacle check
            if (grid[nx][ny] == '#') continue;
            // Already visited check
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (grid[nx][ny] == 'E')
                exitCount++;

            q.push({nx, ny});
        }
    }

    cout << exitCount << "\n";

    return 0;
}