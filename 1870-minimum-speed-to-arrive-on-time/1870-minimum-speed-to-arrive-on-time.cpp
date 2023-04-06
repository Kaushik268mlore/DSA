// class Solution {
// public://a simple binary search with a check will do
//     bool check (vector<int>&d,int mid,int n,double h){
//         int t=0;
//         for(int i=0;i<n-1;i++){
//             t+=(d[i]+mid-1)/mid;
//         }
//         t+=((double)d.back())/mid;
//         return t<=h;
//     }
// //     As speed increases from low to high time decreases so at low speed we take more time and vice versa.As we have to minimise the time taken so we have to keep increasing
// // low (cur speed)=mid(prev speed)+1 ;
// // Take a look at the condition (time <= hour);
// // sequence followed by condition is N N N N N N Y Y Y Y Y ;to get the ans we restrict our search to the Y(yes) itself (We want first yes only) which will be at "hi".
//     int minSpeedOnTime(vector<int>& dist, double hour) {
//         int n=dist.size(),ans;
//         if(hour<=(double)n-1)return -1;
//         int l=1,r=1e7;
//         while(l<=r){
//             int mid=l+(r-l)/2;
//             if(check(dist,mid,n,hour)){
//                 ans=mid;
//                 r=mid-1;}
//             else l=mid+1;
//         }
//     return ans;
//     }
// };
class Solution
{
    bool canReachInTime(const vector<int>& dist, const double hour, int speed)
    {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
            time += ((dist[i] + speed - 1) / speed);
        
        time += ((double)dist.back()) / speed;
        return time <= hour;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int N = dist.size();
        if (hour <= (double)(N - 1))
            return -1;
        
        int lo = 1, hi = 1e7, mi;
        while (lo < hi)
        {
            mi = (lo + hi) / 2;
            if (canReachInTime(dist, hour, mi))
                hi = mi;
            else
                lo = mi + 1;
        }
        
        return hi;
    }
};