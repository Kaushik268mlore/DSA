class Solution {
public:
//     int dp[1000 + 1][1000 + 1];
//     int lcs(string& s1, string& s2, int n, int m)
//     {
//         for (int i = 0; i < n + 1; i++) {
//             for (int j = 0; j < m + 1; j++) {
//                if (i == 0 || j == 0) {
//                    dp[i][j] = 0;
//                } 
//             }
//         }
        
//         for (int i = 1; i < n + 1; i++) {
//             for (int j = 1; j < m + 1; j++) {
//                 if (s1[i - 1] == s2[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = max(0 + dp[i][j - 1], 0 + dp[i - 1][j]);
//             }
//         }

//         return dp[n][m];
//     }
    
//     int longestCommonSubsequence(string s1, string s2) 
//     {
//         memset(dp, -1, sizeof(dp));        
//         return lcs(s1, s2, s1.length(), s2.length());
//     } // iterative
//     memoization
    int f(vector<vector<int>>&dp,int i,int j,string &s1,string &s2){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(dp,i-1,j-1,s1,s2);
        }
        return dp[i][j]=max(f(dp,i-1,j,s1,s2),f(dp,i,j-1,s1,s2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return f(dp,s1.length()-1,s2.length()-1,s1,s2);
    }
};