class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    // for(int i:arr){if(i<=k)k++;}//this isn't my logic , but is some really good shit..
    //     return k;
    // }
    bool check(int m,vector<int>a,int k){
        return a[m]-m-1<k;
    }
    int findKthPositive(vector<int>& arr, int k){//binary search method in O(logn).
        int l=0,r=arr.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(check(mid,arr,k))l=mid+1;
            else r=mid;
        }
    return l+k;}
};