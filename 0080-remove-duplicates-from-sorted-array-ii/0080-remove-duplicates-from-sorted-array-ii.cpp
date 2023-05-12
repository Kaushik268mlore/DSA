class Solution {
public:
//     maintain a window of at-most 2 while removing duplicates
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;
        int cnt=2;
        for(int i=2;i<n;i++){
            if(nums[cnt-2]!=nums[i])nums[cnt++]=nums[i];
            else continue; // just to help me with intuition.
        }
    return cnt;}
};