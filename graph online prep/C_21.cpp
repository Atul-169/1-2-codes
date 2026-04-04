#include <bits/stdc++.h>
using namespace std;

struct Rider {
    int x, y, k;
};

int n, m, q;
vector<Rider> riders;
int tx, ty;

vector<pair<int,int>> knight_moves(int k) {
    return {{k,1},{k,-1},{-k,1},{-k,-1},{1,k},{1,-k},{-1,k},{-1,-k}};
}

int main() {
    cin >> n >> m >> q;
    riders.resize(q);
    for(int i=0;i<q;i++)
        cin >> riders[i].x >> riders[i].y >> riders[i].k;
    
    cin >> tx >> ty;
    
    int total_moves = 0;
    
    for(int i=0;i<q;i++){
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q_cells;
        dist[tx][ty] = 0; // BFS from target
        q_cells.push({tx, ty});
        auto moves = knight_moves(riders[i].k);
        
        while(!q_cells.empty()){
            auto [x,y] = q_cells.front(); q_cells.pop();
            for(auto [dx,dy]: moves){
                int nx = x + dx, ny = y + dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){
                    dist[nx][ny] = dist[x][y]+1;
                    q_cells.push({nx, ny});
                }
            }
        }
        
        if(dist[riders[i].x][riders[i].y]==-1){
            cout << -1 << endl; // this rider cannot reach target
            return 0;
        }
        total_moves += dist[riders[i].x][riders[i].y];
    }
    
    cout << total_moves << endl;
    return 0;
}