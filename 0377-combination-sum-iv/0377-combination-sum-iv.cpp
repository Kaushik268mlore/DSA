class Solution {
public:
    // an iterative bottom -up DP solution
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int coins:nums){
                if(i>=coins){
                    dp[i]+=dp[i-coins];
                }
            }
        }
    return dp[target];}
};