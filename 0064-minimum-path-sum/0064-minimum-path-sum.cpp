class Solution {
private :
    //recursion : TLE
    //memoization :should work
    int m,n;
    // int dfs(vector<vector<int>>&grid,int i,int j){
    //     if(i>n-1||j>m-1)return INT_MAX;
    //     if(i==n-1 && j==m-1)return grid[n-1][m-1]; 
    //     return (grid[i][j]+min(dfs(grid,i,j+1),dfs(grid,i+1,j)));
    // }
     int dfs(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){//memoized version
        if(i>n-1||j>m-1)return INT_MAX;
        if(i==n-1 && j==m-1)return grid[n-1][m-1]; 
         if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=(grid[i][j]+min(dfs(grid,dp,i,j+1),dfs(grid,dp,i+1,j)));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dfs(grid,dp,0,0);
    }
};