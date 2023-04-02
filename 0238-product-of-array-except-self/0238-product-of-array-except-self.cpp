class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int prod=1;
        vector<int>id;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){id.push_back(i);continue;}
            prod*=nums[i];
        }
        if(id.size()==1)ans[id[0]]=prod;
        else if(id.size()==0){
            for(int i=0;i<nums.size();i++){
                ans[i]=prod/nums[i];
            }
        }
    return ans;}
};