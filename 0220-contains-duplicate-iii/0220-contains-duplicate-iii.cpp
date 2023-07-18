class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size(),r=indexDiff;
        set<int>s;
        for(int i=0;i<n;i++){
            if(i>indexDiff){
                s.erase((nums[i-indexDiff-1]));
            }
            auto it=s.lower_bound((nums[i]-valueDiff));
            if(it!=s.end()&&*it-nums[i]<=valueDiff )return true;
            s.insert(nums[i]);
        }
        return false;
    }
};