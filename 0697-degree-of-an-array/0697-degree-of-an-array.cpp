class Solution {
public:
//     int findShortestSubArray(vector<int>& nums) {
//      // int res=1;
//      int n=nums.size();
//      unordered_map<int,int>m;
//         for(int i=0;i<n;i++)m[nums[i]]++;
//         int mode=0,maxfreq=0;
//         for(auto i:m){
//             maxfreq=max(maxfreq,i.second);
//         }
//         if(maxfreq==1)return 1;
//         vector<int>modes;
//         for(auto i:m){
//             if(i.second==maxfreq)modes.push_back(i.first);
//         }
//         int res=INT_MAX;
//         for(int i=0;i<modes.size();i++){
//             res=min(res,wnd(modes[i],nums,n));
//         }
//     return res;}
    
//     int wnd(int mode,vector<int>nums,int n){
//         int left=-1,right=0;
//         for(int i=0;i<n;i++){
//             if(left==-1&&nums[i]==mode)left=i;
//             if(nums[i]==mode)right=i;
//             cout<<left<<" "<<right;
//         }
//     return right-left+1;
//     }
//     above solution is bruteforce, gotta do it more efficiently
    int findShortestSubArray(vector<int>& nums){
//         FKin O(n) time while storing firstOcc and lastOcc in different maps is the way to go , but does take space
        int n=nums.size();
        unordered_map<int,int>beg,end,deg;
        int res=INT_MAX;
        int maxfreq=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            deg[num]++;
            if(beg.find(num)==beg.end())beg[num]=i;
            end[num]=i;
            if(deg[num]>maxfreq){maxfreq=deg[num];res=end[num]-beg[num]+1;}
            else if(deg[num]==maxfreq)res=min(res,end[num]-beg[num]+1);
        }
    return res;}
};