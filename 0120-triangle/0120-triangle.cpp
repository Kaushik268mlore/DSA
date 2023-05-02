class Solution {
public:
    // int dp[200];
    int helper(vector<vector<int>>&tri,int i,int j,vector<vector<int>>&dp,int n){
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=tri[i][j]+helper(tri,i+1,j,dp,n);
        int right=tri[i][j]+helper(tri,i+1,j+1,dp,n);
        return dp[i][j]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(tri,0,0,dp,n);
    }
	
};