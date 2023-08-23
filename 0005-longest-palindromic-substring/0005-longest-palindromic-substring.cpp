class Solution {
public:
//     manachers' algorithm or DP solution.
//     string longestPalindrome(string s) {
// //         state dp[i][j]=true
//         int n=s.length();
//         // if(n==1)return s;
//         vector<vector<bool>>dp(n,vector<bool>(n,false));
//         int ans[2]={0,0};
//         for(int i=0;i<n;i++){
//             dp[i][i]=true;
//         }
//         for(int i=0;i<n-1;i++){
//             if(s[i]==s[i+1]){
//                 dp[i][i+1]=true;
//                 ans[0]=i;
//                 ans[1]=i+1;
//             }
//         }
//         for(int diff=2;diff<n;diff++){
//             for(int i=0;i<n-diff;i++){
//                 int j=i+diff;
//                 if(s[i]==s[j]&&dp[i+1][j-1]==true){
//                     dp[i][j]=true;
//                     ans[0]=i;
//                     ans[1]=j;
//                 }
//             }
//         }
//         int i=ans[0];
//         int j=ans[1];
//         // cout<<i<<" "<<j<<"\n";
//         return s.substr(i,j+1);
//     }
    string str;
    bool f(vector<vector<int>>&dp,int l,int r,vector<int>&sol){
        // if(l>=r||l>=str.length()||r<0)return 0;
        if(l>=r)return 1;
        bool found=0;
        if(dp[l][r]!=-1)return dp[l][r];
        if(str[l]==str[r]){
            found=1&&f(dp,l+1,r-1,sol);
        }
        f(dp,l+1,r,sol);
        f(dp,l,r-1,sol);
        if(found&&(r-l+1)>sol[2]){
            sol={l,r,r-l+1};
        }
        return dp[l][r]=found;
    }
     string longestPalindrome(string s){
         str=s;
         // if(s.length()==1)return ;
         vector<int>ans={0,0,1};
         vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
         f(dp,0,s.length()-1,ans);
         return s.substr(ans[0],ans[2]);
     }
};