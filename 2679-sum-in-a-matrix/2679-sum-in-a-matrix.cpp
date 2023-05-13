class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int res=0;
        vector<priority_queue<int>>vp(n);
        for(int i=0;i<n;i++){
            vp[i]=priority_queue<int>(nums[i].begin(),nums[i].end());
        }
    for(int j=0;j<m;j++){
        int tmp=0;
        for(int i=0;i<n;i++){
            tmp=max(vp[i].top(),tmp);
            vp[i].pop();
        }
        res+=tmp;
    }
    return res;}
};