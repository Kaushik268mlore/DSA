class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // //pretty simple solution ,it seems,nah TLE here so gotta alter the code.
        //holy crap dis be some sliding window problem and I frickin missed the logic...lol
        // unordered_map<int,int>m;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int maxx=INT_MIN;
        //     for(int j=i;j<n;j++){
        //         maxx=max(maxx,nums[j]);
        //         m[maxx]++;
        //     }
        // }
        // int ans=0;
        // for(int i=left;i<=right;i++){
        //     ans+=m[i];
        // }
            //trust me when I say sliding window's a beuat
        int n=nums.size(),l=-1,r=-1,ans=0; //the -1's for the addition due to indexing being 0
        for(int i=0;i<n;i++){
            if(nums[i]>right)l=i;
            if(nums[i]>=left)r=i;
            ans+=(r-l);
        }
    return ans;}
};