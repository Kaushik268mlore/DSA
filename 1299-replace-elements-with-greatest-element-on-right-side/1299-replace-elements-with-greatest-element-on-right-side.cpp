class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=size(arr);
        if(n==1)return {-1};
        int ele=-1;
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            arr[i]=ele;
            ele=max(ele,curr);
        }
    return arr;}
};