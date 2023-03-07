class Solution {
public:
    //again a binary search problem 
    bool check(long long mid,vector<int>arr,int k){
        long long tot=0;
        for(int i:arr)tot+=(mid/i);
        return tot>=k;
    }
    long long minimumTime(vector<int>&arr, int totalTrips) {
        long long l=1;
        long long r=1LL * (*max_element(arr.begin(),arr.end()))*totalTrips;
        while(l<r){
            long long mid=l+(r-l)/2;
            if(check(mid,arr,totalTrips))r=mid;
            else l=mid+1;
        }
    return l;}
};