class Solution {
public:
   /* int numTrees(int n) {           //catalan numbers solution
                long ans = 1;
        for(int i = 1; i < n; i++)  
            ans = ans*(n+i+1) / i;    // do note that numerator and denominator will always be divisible
        return ans / n;
    }*/
    int dp[21];
    int numTrees(int n){//using dp
        if(n<=1)return 1;
        if(dp[n])return dp[n];
        for(int i=1;i<=n;i++){
            dp[n]+=numTrees(i-1)*numTrees(n-i);
        }
         return dp[n];
    }
};