class Solution {
public:
    //this could be applying bfs/dfs and check if it leads to the boundaries and then , 
    //or you could bfs from the boundaries and see which leads to mark them as non enclaves.(this approach is real smart.)
    // void dfs(int r,int c,int n,int m,vector<vector<int>>mat,vector<vector<bool>>&vis){
    //     if(r<0||c<0||r>n||c>m||mat[r][c]!=1||vis[r][c])return;//base case
    //     vis[r][c]=true;
    //     int dy[]={-1,0,1,0};
    //     int dx[]={0,1,0,-1};
    //     for(int i=0;i<4;i++){
    //         int nx=dx[i]+r;
    //         int ny=dy[i]+c;
    //         dfs(nx,ny,m,n,mat,vis);
    //     }
    //     return;
    // }
    // int numEnclaves(vector<vector<int>>& grid) {
    //     //dfs on the rows
    //     int n=grid.size(),m=grid[0].size();
    //     vector<vector<bool>>vis(n,vector<bool>(m,false));
    //     for(int i=0;i<m;i++){
    //         if(grid[0][i]==1&&!vis[0][i])dfs(0,i,n,m,grid,vis);
    //         if(grid[n-1][i]==1&&!vis[n-1][i])dfs(n-1,i,n,m,grid,vis);
    //     }
    //     //dfs on columns
    //     for(int i=0;i<n;i++){
    //         if(grid[i][0]==1&&!vis[i][0])dfs(i,0,n,m,grid,vis);
    //         if(grid[i][m-1]==1&&!vis[i][m-1])dfs(i,m-1,n,m,grid,vis);
    //     }
    //     //after these all the 1s tht cannot be enclaved are visited
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j] and !vis[i][j])cnt++;
    //         }
    //     }
    // return cnt;}
    //well the one below is a bfs solution.
    void bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;   // row nnumber
            y = q.front().second;  // column number
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    continue;
                } else if (grid[r][c] == 1 && !visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1 && !visit[i][0]) {
                bfs(i, 0, m, n, grid, visit);
            }
            // Last column.
            if (grid[i][n - 1] == 1 && !visit[i][n - 1]) {
                bfs(i, n - 1, m, n, grid, visit);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1 && !visit[0][i]) {
                bfs(0, i, m, n, grid, visit);
            }
            // Last row.
            if (grid[m - 1][i] == 1 && !visit[m - 1][i]) {
                bfs(m - 1, i, m, n, grid, visit);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};