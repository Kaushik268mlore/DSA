class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]>t){
                r--;
            }
            else if(nums[l]+nums[r]<t){
                l++;
            }
            else return {l+1,r+1};
        }
    return{-1,-1};}
};