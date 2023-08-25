class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long int n=nums.size(),ans=1,j=0,sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while((i-j+1)*nums[i]-sum>k){
                sum-=nums[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
    return ans;}
};
// sliding window