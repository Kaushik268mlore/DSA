class Solution {
public:
//     simple binary search 
    bool check (long ind,long mid,long n,long maxSum){
        long sum=0;
//         left sum
     if(mid>ind)sum+=(mid+mid-ind)*(ind+1)/2;
     else sum+=(mid+1)*mid/2+ind-mid+1;
//         right sum
    if(mid>=n-ind){
//              increasinfg AP
            sum+=(mid+mid-n+1+ind)*(n-ind)/2;
    }
    else sum+=(mid+1)*mid/2+n-ind-mid;
    return sum-mid<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=maxSum;
        while(l<r){
            long mid=(l+r+1)/2;
            if(check(index,mid,n,maxSum))l=mid;
            else r=mid-1;
        }
    return l;}
};