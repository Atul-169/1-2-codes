#include <bits/stdc++.h>
using namespace std;

struct Rider {
    int x, y, k;
};

int n, m, q, d;
vector<Rider> riders;
bool death[105][105]; // death squares

vector<pair<int,int>> knight_moves(int k) {
    return {{k,1},{k,-1},{-k,1},{-k,-1},{1,k},{1,-k},{-1,k},{-1,-k}};
}

void bfs(const Rider &r, vector<vector<int>> &dist) {
    queue<pair<int,int>> q_cells;
    dist[r.x][r.y] = 0;
    q_cells.push({r.x, r.y});
    
    auto moves = knight_moves(r.k);
    
    while(!q_cells.empty()) {
        auto [x,y] = q_cells.front();
        q_cells.pop();
        for(auto [dx, dy] : moves) {
            int nx = x + dx, ny = y + dy;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !death[nx][ny]) {
                if(dist[nx][ny]==-1) {
                    dist[nx][ny] = dist[x][y]+1;
                    q_cells.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    riders.resize(q);
    for(int i=0;i<q;i++)
        cin >> riders[i].x >> riders[i].y >> riders[i].k;
    
    cin >> d;
    memset(death, false, sizeof(death));
    for(int i=0;i<d;i++) {
        int x, y;
        cin >> x >> y;
        death[x][y] = true;
    }
    
    // BFS distance for each rider
    vector<vector<vector<int>>> all_dist(q, vector<vector<int>>(n, vector<int>(m, -1)));
    for(int i=0;i<q;i++) {
        if(death[riders[i].x][riders[i].y]) {
            cout << -1 << endl; // rider starts on death square
            return 0;
        }
        bfs(riders[i], all_dist[i]);
    }
    
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(death[i][j]) continue; // cannot end on death square
            int sum_moves = 0;
            bool possible = true;
            for(int r=0;r<q;r++){
                if(all_dist[r][i][j]==-1) { possible=false; break; }
                sum_moves += all_dist[r][i][j];
            }
            if(possible) ans = min(ans, sum_moves);
        }
    }
    
    if(ans==INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}