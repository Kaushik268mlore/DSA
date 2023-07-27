class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]&1)m[1].push_back(nums[i]);
            else m[0].push_back(nums[i]);
        }
        vector<int>res;
        for(int i=0;i<m[0].size();i++){
            res.push_back(m[0][i]);
        }
        for(int i=0;i<m[1].size();i++)res.push_back(m[1][i]);
        return res;
    }
};