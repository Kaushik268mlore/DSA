class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[101][101]={};
        dp[0][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
    return dp[n][m];}
};