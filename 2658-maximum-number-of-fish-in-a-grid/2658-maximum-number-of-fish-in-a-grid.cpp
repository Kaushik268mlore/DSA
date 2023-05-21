class Solution {
public:
    // vector<int>res;
    bool check(vector<vector<int>>a,int i,int j){
        return(i>=0&&i<a.size()&&j>=0&&j<a[0].size());
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(!check(grid,i,j)||grid[i][j]==0)return 0;
        int dr[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        int res=grid[i][j];
        grid[i][j]=0;
        for(int l=0;l<4;l++){
            res+=dfs(grid,i+dr[l][0],j+dr[l][1]);
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rs=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0)rs=max(rs,dfs(grid,i,j));
            }
        }
    return rs;}
};