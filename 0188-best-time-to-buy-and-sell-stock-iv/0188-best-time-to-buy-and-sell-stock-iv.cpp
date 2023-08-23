class Solution {
public:
    // int maxProfit(int k, vector<int> &prices) {
    //     int len = prices.size();
    //     if (len<2) return 0;
    //     if (k>len/2){ // simple case
    //         int ans = 0;
    //         for (int i=1; i<len; ++i){
    //             ans += max(prices[i] - prices[i-1],0);
    //         }
    //         return ans;
    //     }
    //     int hold[k+1];
    //     int rele[k+1];
    //     for (int i=0;i<=k;++i){
    //         hold[i] = INT_MIN;
    //         rele[i] = 0;
    //     }
    //     int cur;
    //     for (int i=0; i<len; ++i){
    //         cur = prices[i];
    //         for(int j=k; j>0; --j){
    //             rele[j] = max(rele[j],hold[j] + cur);
    //             hold[j] = max(hold[j],rele[j-1] - cur);
    //         }
    //     }
    //     return rele[k];
    // }//iterative approach
    int f(vector<vector<vector<int>>>&dp,int k,vector<int>&prices,int c,bool buy,int i){
        if(i>=prices.size()||c>=k)return 0;
        // if(i==price.size&&c<=k)return 
        if(dp[i][buy][c]!=-1)return dp[i][buy][c];
        int skip=f(dp,k,prices,c,buy,i+1);
        if(buy){
            return dp[i][buy][c]=max(skip,-prices[i]+f(dp,k,prices,c,!buy,i+1));
        }
        else {
            return dp[i][buy][c]=max(skip,prices[i]+f(dp,k,prices,c+1,!buy,i+1));
        }
    return 0;}
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(dp,k,prices,0,1,0);
    }
};