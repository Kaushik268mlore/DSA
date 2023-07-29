class Solution {
public:
//     clearly a DP problemmm
    int ops(int i,int j,string w1,string w2,vector<vector<int>>&dp){
//         base case 
        if(i<0){return j+1;}
        if(j<0){return i+1;}
        if(w1[i]==w2[j])return dp[i][j]=ops(i-1,j-1,w1,w2,dp);
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min(ops(i-1,j,w1,w2,dp),min(ops(i-1,j-1,w1,w2,dp),ops(i,j-1,w1,w2,dp)));
    }
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ops(n-1,m-1,w1,w2,dp);
    }
};