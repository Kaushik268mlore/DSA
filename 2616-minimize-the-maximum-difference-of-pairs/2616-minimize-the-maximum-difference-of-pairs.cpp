class Solution {
public:
//     heap approach..
    // int minimizeMax(vector<int>& nums, int p) {
    //     int n=nums.size();
    //     int cnt=n-min(n,p);
    //     priority_queue<int>pq;
    //     sort(nums.begin(),nums.end());
    //     for(int i=1;i<n;i+=2){
    //         pq.push(abs(nums[i]-nums[i-1]));
    //     }
    //     for(int i=0;i<cnt-1;i++){
    //         pq.pop();
    //     }
    //     return pq.top();
    // }
//     binary search approach...
    int minimizeMax(vector<int>& nums, int p){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=l+(r-l)/2,cnt=0;
            for(int i=1;i<n;i++){
                if(nums[i]-nums[i-1]<=mid)cnt++,i++;
            }
            if(cnt<p)l=mid+1;
            else r=mid;
        }
        return l;
    }
};