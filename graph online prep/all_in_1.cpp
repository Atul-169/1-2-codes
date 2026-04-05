int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0, time = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2) q.push({i,j});
            if(grid[i][j] == 1) fresh++;
        }
    }

    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    while(!q.empty() && fresh > 0){
        int sz = q.size();
        time++;

        while(sz--){
            auto [x,y] = q.front(); q.pop();

            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
        }
    }

    return fresh == 0 ? time : -1;
}
void dfs(vector<vector<char>>& grid, int i, int j){
    int n = grid.size(), m = grid[0].size();

    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;

    grid[i][j] = '0';

    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}
void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
    visited[node] = true;

    for(int j=0;j<isConnected.size();j++){
        if(isConnected[node][j] == 1 && !visited[j]){
            dfs(j, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n,false);
    int count = 0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(i, isConnected, visited);
        }
    }
    return count;
}
void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor){
    int n = image.size();
    int m = image[0].size();

    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(image[i][j] != oldColor) return;

    image[i][j] = newColor;

    dfs(image, i+1, j, oldColor, newColor);
    dfs(image, i-1, j, oldColor, newColor);
    dfs(image, i, j+1, oldColor, newColor);
    dfs(image, i, j-1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];

    if(oldColor == newColor) return image;

    dfs(image, sr, sc, oldColor, newColor);
    return image;
}
int dfs(vector<vector<int>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    // boundary + water check
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return 0;

    // mark visited
    grid[i][j] = 0;

    // count this cell + neighbors
    return 1 
        + dfs(grid, i+1, j)
        + dfs(grid, i-1, j)
        + dfs(grid, i, j+1)
        + dfs(grid, i, j-1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int maxArea = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                int area = dfs(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}
int dfs(vector<vector<int>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    // stop condition
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return 0;

    // mark visited
    grid[i][j] = 0;

    // count current + neighbors
    return 1 
        + dfs(grid, i+1, j)
        + dfs(grid, i-1, j)
        + dfs(grid, i, j+1)
        + dfs(grid, i, j-1);
}

vector<int> countIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> islandSizes;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                int size = dfs(grid, i, j);
                islandSizes.push_back(size);
            }
        }
    }

    return islandSizes;
}
