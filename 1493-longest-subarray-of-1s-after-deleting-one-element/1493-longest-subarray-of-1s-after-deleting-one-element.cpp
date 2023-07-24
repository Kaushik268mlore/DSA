class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,z=0,ans=0;
        if(n==1||n==0)return 0;
        for(int i=0;i<n;i++){
            z+=nums[i]==0;
            while(z>1){z-=nums[j++]==0;}
            ans=max(ans,i-j);
        }
    return ans;}
};
