class Solution {
public:
    int dp[101]{};
    int rob(vector<int>& nums) {
       //non-dp solution
        int ans=INT_MIN,prev=0,curr=0;
        for(int i=0;i<nums.size();i++){
            int t=max(prev+nums[i],curr);
            prev=curr;
            curr=t;
        }
        return curr;
    }
};