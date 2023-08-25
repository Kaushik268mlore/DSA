class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),z=0,ans=0,j=0;
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            z+=(nums[i]==0);
            while(z>k)z-=(nums[j++]==0);
            ans=max(ans,i-j+1);
        }
    return ans;}
};   
// too simple
