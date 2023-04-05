class Solution {
public:
    //seems like some greedy approach would work.
    //so basically, as we keep calculating the prefix , the more we distribute the integers to the left of a 
    // max number (even after doing the operations , the prefix sum doesn't change)
    //hence average will tell you the minimum , maximum integer possible within the array
    int minimizeArrayValue(vector<int>& nums) {
        long long int psum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            ans=max(ans,(psum+i)/(i+1));        //this basically is getting getting ceil in integers
        }
    return ans;
    }
};