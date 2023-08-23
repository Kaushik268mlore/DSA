class Solution {
public:
    // int dp[1000];
//     iterative DP , I kinda hate this shid....
    // int numDecodings(const string& s) {
    //     int n = s.size();
    //     dp[n] = 1;
    //     for (int i = n - 1; i >= 0; --i) {
    //         if (s[i] != '0') // Single digit
    //             dp[i] += dp[i+1];
    //         if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
    //             dp[i] += dp[i+2];
    //     }
    //     return dp[0];
    // }
    
//     lemmme memoize this shid, that's cooler
    int n;
    int f(string s,vector<int>&dp,int id){
        // n=s.length();
        if(id>=n)return 1;
        if(id<n&&s[id]=='0')return 0;   // instead of passing the remaining substring as the subproblem 
        // it looks feasible to mark the visisted chars in the string..
        if(dp[id]!=-1)return dp[id];
        int poss=0;
        if(s[id]!='0')poss=f(s,dp,id+1);
        if (id+1<n&&(s[id]=='1'||s[id]=='2'&&s[id+1]<='6')){
            poss+=f(s,dp,id+2);
        }
        return dp[id]=poss;
    }
    int numDecodings(const string& s){
        n=s.length();
        vector<int>dp(s.length(),-1);
        return f(s,dp,0);
    }
};
    