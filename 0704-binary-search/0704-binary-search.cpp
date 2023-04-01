class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l=0,h=nums.size()-1;
        while(l<h){
            int mid= h-(h-l)/2;
           if(nums[mid]>target)h=mid-1;
            else{
                l=mid;
            }
        }
        return (nums[l]==target)?l:-1;
    }
};