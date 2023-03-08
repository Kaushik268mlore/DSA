class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {//okay so this problem is based on the cancelling property of XOR, xor the same number even times , u get 0, else u get the number itself, 
// just look at the final product , after XORing the whole nums3 array , it'll pretty much be the same thing as the number of times each element occurs times the XOR of each array.O(n) time and I
        int ans=0;
        if(size(nums1)&1)for(int i:nums2)ans^=i;
        if(size(nums2)&1)for(int i:nums1)ans^=i;
        return ans;
    }
};