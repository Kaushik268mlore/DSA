class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        long long cnt=0,res=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i];
            if(cnt>0)res++;
        }
    return res;}
};