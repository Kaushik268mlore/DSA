class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int>pre(nums.size());
        pre[0]=nums[0];
        int n=nums.size();
        int res=0;
        int sol=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
            sol=min(res,sol);
        }
        return abs(sol)+1;
        
    }
};