class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            ++m[nums[i]];
            if(m[nums[i]]>1)return true;
               
        }
        return false;
    }
};