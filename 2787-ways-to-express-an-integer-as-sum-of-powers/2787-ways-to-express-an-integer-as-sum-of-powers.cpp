// #define LL long long 
// class Solution {
// public:
//     // vector<vector<LL>>dp(305,vector<LL>(305,-1));
//     // vector<vector<LL>>dp(305,vector<LL>(305, -1));
//     LL dp[305][305];
//     LL mod=1e9+7;
//     int f(LL n,LL x,LL i){
//         if(n==0)return 1;
//         if(n<0||pow(i,n)>n)return 0;
//         if(dp[n][i]!=-1)return dp[n][i];
//         LL yes=f(n-pow(i,x),x,i+1);
//         LL no=f(n,x,i+1);
//         LL res=yes+no;
//         return dp[n][i]=res%mod;
//     }
//     int numberOfWays(int n, int x) {
//         memset(dp,-1,sizeof(dp));
//         return f(n,x,1);
//     }
// };
class Solution {
public:
    long long dp[305][305];
    int mod=1e9+7;
    long long solve(long long n,long long x,long long i){
        if(n==0) return 1;
        if(n<0 || pow(i,x)>n) return 0;
        if(dp[n][i]!=-1) return dp[n][i];

        long long take=solve(n-pow(i,x),x,i+1);
        long long nottake=solve(n,x,i+1);

        long long sum=(take+nottake)%mod;
        return dp[n][i]=sum;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans=solve(n,x,1);
        return ans;
    }
};