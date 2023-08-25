class Solution {
public:
//     Simple sliding window
    int maximumUniqueSubarray(vector<int>& nums) {
        unsigned int n=nums.size(),i=0,j=0,sum=0,ans=0;
        vector<int>m(10001,0);
        for(int i=0;i<n;i++){
            while(i>j&&m[nums[i]]>=1){
                m[nums[j]]--;
                sum-=nums[j++];
            }
            m[nums[i]]++;
            sum+=nums[i];
            ans=max(ans,sum);
        }
    return ans;
    }
};