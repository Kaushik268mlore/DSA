class Solution {
public:
    //similar problem as number of islands. cool dfs 
    int m,n;
    bool dfs(vector<vector<int>>&mp,int x,int y,vector<vector<bool>>&vis){
        int dy[]={-1,0,1,0};
        int dx[]={0,1,0,-1};
        if(x<0||x>=m||y<0||y>=n)return false;
        if(mp[x][y]==1||vis[x][y])return true;
        bool flag=true;
        vis[x][y]=true;
          for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
              if(!dfs(mp,nx,ny,vis))flag=0;
          }
           return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt=0;
        vector<vector<bool>>vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0&&!vis[i][j]&&dfs(grid,i,j,vis))cnt++;
            }
        }
    return cnt;
    }
};