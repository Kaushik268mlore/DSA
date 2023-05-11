class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m=*max_element(nums.begin(),nums.end());
        return ((k)*(m+m+k-1))>>1;
    }
};