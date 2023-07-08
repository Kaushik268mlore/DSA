class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>res(nums1.size()+nums2.size(),0);
        int n=nums1.size(),m=nums2.size();
        int l=res.size();
        int j=0,k=0;
        for(int i=0;i<l;i++){
            res[i]=k==m||(j<=n-1&&nums1[j]<nums2[k])?nums1[j++]:nums2[k++];
        }
        // double ans=0;
        if(l&1)return res[l/2];
        return (res[l/2-1]+res[l/2])/2;
    }
};