class Solution {
public:
//     memoization
    // int f(vector<int>cost,int id,vector<int>&dp){
    //     if(id>=cost.size())return 0;
    //     if(dp[id]!=-1)return dp[id];
    //     return dp[id]=cost[id]+min(f(cost,id+1,dp),f(cost,id+2,dp));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int>dp(cost.size(),-1);
    //     return min(f(cost,0,dp),f(cost,1,dp));
    // }
//     tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
                dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        dp[cost.size()]=min(dp[cost.size()-1],dp[cost.size()-2]);
        return dp[cost.size()];
    }
};