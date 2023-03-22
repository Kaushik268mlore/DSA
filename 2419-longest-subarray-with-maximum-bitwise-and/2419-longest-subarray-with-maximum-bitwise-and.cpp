class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxx=*max_element(nums.begin(),nums.end());
        int cnt =0,res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxx)cnt++,res=max(res,cnt);
            else cnt=0;
        }
    return res;}
};