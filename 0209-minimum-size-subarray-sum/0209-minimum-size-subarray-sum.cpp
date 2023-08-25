#define LL long long int
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        LL sum=0,t=0,n=nums.size(),ans=INT_MAX,l=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            t+=nums[i];
            if(i==n-1&&t<target){return 0;}
            while(sum>=target){
               ans= min(ans,i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};