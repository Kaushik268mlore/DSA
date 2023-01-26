class Solution {
public:
    int dp[101]{};
    /*int rob(vector<int>& nums) {
       //non-dp solution
        int ans=INT_MIN,prev=0,curr=0;
        for(int i=0;i<nums.size();i++){
            int t=max(prev+nums[i],curr);
            prev=curr;
            curr=t;
        }
        return curr;
    }*/
    int rob(vector<int>& nums){//dp solution
        int n=size(nums);
        if(n==1)return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};