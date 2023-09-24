class Solution {
public:
    vector<vector<int>>pset;//backtracking solution
    void generate(vector<int>nums,vector<int>&res,int idx){
        if(idx>=nums.size()){
            pset.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        generate(nums,res,idx+1);
        res.pop_back();
        generate(nums,res,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        generate(nums,res,0);
        return pset;
    }
};