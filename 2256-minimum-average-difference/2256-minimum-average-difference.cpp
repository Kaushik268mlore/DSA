class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {//prefix and suffix sum array.
        vector<vector<long long>>pre(nums.size()+1,vector<long long>(2));
       // vector<int>avg;
        int n=size(nums);
        for(int i=0;i<n;i++){
            pre[i+1][0]=pre[i][0]+nums[i];
            
        }
        for(int i=n-1;i>=0;i--){
            pre[i][1]=nums[i]+pre[i+1][1];
        }
        long long minDiff=INT_MAX;
        int minID=size(nums);
        for(int i=0;i<size(nums);i++){
            long long leftavg=pre[i+1][0];
            long long int rightavg=pre[i+1][1];
            leftavg/=(i+1);
            if(i!=n-1)rightavg/=(n-i-1);
            long long int currdiff=abs(leftavg-rightavg);
            if(currdiff<minDiff){
                minDiff=currdiff;
                minID=i;
            }
        }
    return minID;}
};