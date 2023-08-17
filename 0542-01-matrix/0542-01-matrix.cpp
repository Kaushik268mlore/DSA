class Solution {
public:
//     DP-SUBMATRIX with BFS is the most probabale approach.
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int dx[]={0,1,-1,0};
        int dy[]={-1,0,0,1};
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(mat[i][j]==0) vis[i][j]=0,q.push({i,j});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x<n and y<m and x>=0 and y>=0 and vis[x][y]==-1){
                    vis[x][y]=1+vis[i][j];
                    q.push({x,y});
                }
            }
        }
        return vis;
    }
    
};