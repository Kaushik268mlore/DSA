class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>res(n-k+1,0);
    //     for(int i=0;i<n-k+1;i++){
    //         int mx=INT_MIN;
    //         for(int j=i;j<i+k;j++)mx=max(nums[j],mx);
    //         res[i]=mx;
    //     }
    // return res;}
//     for obvious reasons , if the problem was this easy , it won't have been tagged hard.
//     okay, so we have to find the maximum in the window , in O(1).. else the cases wont pass, only 
//     way is to use a monotonic queue. a decreasing one..
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n=nums.size();
        vector<int>res;
        deque<int>q;
        for(int i=0;i<n;i++){
            while(!q.empty()&&i-q.front()>=k)q.pop_front();
            while(!q.empty()&&nums[q.back()]<nums[i])q.pop_back();
            q.push_back(i);
            if(i>=k-1)res.push_back(nums[q.front()]);
        }
    return res;}
};