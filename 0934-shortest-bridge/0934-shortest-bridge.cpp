class Solution {
public:
//     feels like a BFS solution , that can be used to get the bridge length, while we can use DFS for recognising the islands.
    // int n,m;
    bool check(int i,int j,vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    queue<pair<int,int>>q;
    void dfs(vector<vector<int>>&grid, int i,int j){
        if(!check(i,j,grid)||grid[i][j]==0||grid[i][j]==2){return;}
        grid[i][j]=2;
         q.push({i,j}); // we are pushing the locations of the initial islands and mark them 2 so that we can distinguish from a neighbouring island..
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
    }
    int min_bfs(vector<vector<int>>&grid){
        int dist=0;
        int res=INT_MAX;
        while(q.size()!=0){
            int n=q.size();
            while(n-->0){
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                auto p=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                int currx=p.first+dx[i],curry=p.second+dy[i];
                    // currx+=dx[i];
                    // curry+=dy[i];
                    if(check(currx,curry,grid)&&grid[currx][curry]==1){res=min(res,dist);}
                    else if(check(currx,curry,grid)&&grid[currx][curry]==0){
                        q.push({currx,curry});// building the bridge.
                        grid[currx][curry]=2;
                    }
                }
            }
            dist++; // as we cover layers 
        }
    return res;}
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        bool flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!flag){
                 dfs(grid,i,j);
                q.push({i,j});
                flag=1;
                break;
                }
            }
            if(flag)break;
        }
    return min_bfs(grid);
    }
};