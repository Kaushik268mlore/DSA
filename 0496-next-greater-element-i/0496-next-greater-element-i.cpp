class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++)m[nums2[i]]=i;
        vector<int>res;
        for(int i=0;i<n;i++){
            int ele=nums1[i];
            int flag=0;
            for(int j=m[ele];j<nums2.size();j++){
                if(nums2[j]>ele){flag=1;res.push_back(nums2[j]);break;}
            }
            if(!flag)res.push_back(-1);
        }
    return res;}
};