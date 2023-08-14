class Solution {
public:
//     mad binary search problem, with a predicate
    int sum(int mid,vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
           sum+=(arr[i]+mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int l=1,r=*max_element(arr.begin(),arr.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(sum(mid,arr)>threshold)l=mid+1;
            else r=mid;
        }
        return l;
    }
};