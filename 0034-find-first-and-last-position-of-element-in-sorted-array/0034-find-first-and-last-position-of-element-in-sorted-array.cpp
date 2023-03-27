
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
       int id1=bin_srch(nums,target);
        int id2=bin_srch(nums,target+1)-1;
        if(id1<nums.size() and nums[id1]==target){
            return {id1,id2};
        }
        return {-1,-1};
    }
    int bin_srch(vector<int>& nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};