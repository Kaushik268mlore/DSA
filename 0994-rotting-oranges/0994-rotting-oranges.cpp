class Solution {
public:
    //a bfs solution ,this is a problem where the levels matter. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),fresh=0;
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
                if (grid[i][j]==1)fresh++;
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0,enter=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    enter++;
                }
            }
        }
        if(enter!=fresh)return -1;
    return ans;}
};