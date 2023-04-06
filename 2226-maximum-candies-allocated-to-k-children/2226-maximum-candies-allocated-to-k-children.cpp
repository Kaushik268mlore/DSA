class Solution {
public:
//     //straightaway seems like binary search 
// //      (left + right) / 2 to find first element valid
// // mid = (left + right + 1) / 2to find last element valid , i.e by calculating the ceil all the time 
//     vector<int>dumm;
//     long long int off,n;
//     bool check(long long int mid){
//         if(mid==0)return true;
//         long long int cnt=0;
//         for(int i=0;i<n;i++){
//             if(cnt<off)cnt+=(dumm[i]/mid);
//             else break;
//         }
//     return cnt>=off;
//     }
//     int maximumCandies(vector<int>& candies, long long k) { 
//         long long int l=0,r=accumulate(candies.begin(),candies.end(),0);
//         dumm=candies;
//         off=k;
//         n=candies.size();
//         long long int ans=0;
//         // if(n==1&&candies[0]<k)return 0;
//         while(l<=r){
//             long long int mid=l+(r-l)/2;
//             if(check(mid)){ans=mid;l=mid+1;}
//             else r=mid-1;
//         }
//     return ans;}
        bool check(vector<int> &can, long long k, long m){
        long c = 0;
        if(m==0) return true;
        for(auto it:can) c += it/m;
        return c>=k;
    }
    
    int maximumCandies(vector<int>& can, long long k) {
        long long total = 0, ans = 0;
        for(auto it:can)total += it;
        long long l = 0, r = total;
        while(l<=r){
            long mid = (l+r)/2;
            if(check(can, k,mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};