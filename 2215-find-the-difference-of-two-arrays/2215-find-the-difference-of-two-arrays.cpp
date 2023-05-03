class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        //very easy solution using sets 
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        vector<vector<int>>res(2,vector<int>());
        for(int x:s1)(s2.count(x)==0)?res[0].push_back(x):void();            
        for(int x:s2)(s1.count(x)==0)?res[1].push_back(x):void();            
        return res;
    }
};