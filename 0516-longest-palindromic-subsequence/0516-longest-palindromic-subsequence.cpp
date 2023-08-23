// class Solution {
// public:
//     //clearly a DP problem
//     int longestPalindromeSubseq(string s) {
//         // str=s;
//          // if(s.length()==1)return ;
//          // vector<int>ans={0,0,1};
//          vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
//          return f(dp,0,s.length()-1,s);
//          // return s.substr(ans[0],ans[2]);
//         // return ans[2];
//     }
//     string str;
//     int f(vector<vector<int>>&dp,int l,int r,string s){
//         // if(l>=r||l>=str.length()||r<0)return 0;
//         if(l>r)return 0;
//         if(l==r)return 1;
//         // bool found=0;
//         if(dp[l][r]!=-1)return dp[l][r];
//         if(s[l]==s[r]){
//             return dp[l][r]=f(dp,l+1,r-1,s)+2;
//         }
        
//         return dp[l][r]=max(f(dp,l+1,r,s),f(dp,l,r-1,s));
//     }
// //      string longestPalindrome(string s){
         
// //      }
// };
class Solution {
public:
    int dp[1000][1000];
    int f(int l, int r, string &s) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = s[l] == s[r] ? 2 + f(l+1, r-1, s) : max(f(l+1, r, s),f(l, r-1, s));  
    }
        int longestPalindromeSubseq(string s) { 
        memset(dp, -1, sizeof(dp));
        return f(0, s.size()-1, s); 
    }
};