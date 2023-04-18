class Solution {
public:
    // one way could be to check if there exists tot/2 in all the possible sums, put into a set.
    //that'd be fairly optimised
    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        unordered_set<int>sums;
        int target=tot/2;
        if(tot&1)return false;
        else{
            // sort(nums.begin(),nums.end());
            // int pre=nums[0];
            sums.insert(0);
            for(int i=0;i<n;i++){
                unordered_set<int>dum=sums;
                for(int ele:sums){
                    if(ele+nums[i]==target)return true;
                    dum.insert(nums[i]+ele);
                    dum.insert(ele);
                }
                sums=dum;
            }
        }
    return (sums.find(target)!=sums.end());}
};