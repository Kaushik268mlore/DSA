class Solution {
public:
    int help(vector<int> nums){
        int rob1=0,rob2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         int newrob=max(rob1+nums[i],rob2);
         rob1=rob2;
            rob2=newrob;
        }
    return rob2;
    }
    int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    vector<int>rnorm=nums;
        nums.pop_back();
    vector<int>norm=nums;
        rnorm[0]=0;
        return max(help(norm),help(rnorm));
    }
};