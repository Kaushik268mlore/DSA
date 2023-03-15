class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int l=0,r=arr.size()-1,lsum=0;
       int tot=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<=r;i++){
            if(tot-lsum-arr[i]==lsum)return i;
            lsum+=arr[i];
        }
    return -1;}
};