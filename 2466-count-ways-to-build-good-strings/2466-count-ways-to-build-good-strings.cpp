class Solution {
public:
//     memoization 
    const int mod=1e9+7;
    int rec(vector<int>&dp,int z,int o,int end){
        if(end==0)return 1;
        if(dp[end]!=-1)return dp[end];
        int cnt=0;
        if(end>=o)cnt+=rec(dp,z,o,end-o);
        if(end>=z)cnt+=rec(dp,z,o,end-z);
        return dp[end]=cnt%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        // dp[0]=1;
        long long res=0;
        for(int i=low;i<=high;i++){
            res+=rec(dp,zero,one,i)%mod;
        }
        return res%mod;
    }
};