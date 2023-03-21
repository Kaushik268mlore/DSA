class Solution {
public:
    // this problem can be solved using the prefix XOR and then map it 
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int>m;
        m[0]=1;
        long long res=0, pre=0;
        for(int i=0;i<nums.size();i++){
            pre^=nums[i];
            res+=m[pre];
            m[pre]++;
        }
    return res;
    }
};