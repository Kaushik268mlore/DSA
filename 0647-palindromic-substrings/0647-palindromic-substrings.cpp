class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,string s){
        if(i>=j)return 1;// because its the base case and there's no need to continue;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=f(i+1,j-1,dp,s);
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.length(),cnt=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
             cnt+=f(i,j,dp,s);   
            }
        }
    return cnt;
    }
};