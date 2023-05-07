class Solution {
public:
    // here dp[i] = LIS[0..i] 
    //recurrence relation : if(a greater number is found ) if(nums[i]>nums[j]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1
    // as they are asking for the longest increasing subsequence return the longest in dp array.
   // int lengthOfLIS(vector<int>& nums) {
   //      int n = nums.size();
   //      vector<int> dp(n, 1);
   //      for (int i = 0; i < n; ++i)
   //          for (int j = 0; j < i; ++j)
   //              if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
   //                  dp[i] = dp[j] + 1;
   //      return *max_element(dp.begin(), dp.end());
   //  }
    // hiepit's binary search solution...
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the first element >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};