class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=size(nums);
        vector<int>arr(n+1,0);
        for(int i:nums){
            arr[i]++;
        }
        vector<int>res;
        for(int i=1;i<=n;i++){
            if(arr[i]==0)res.push_back(i);
        }
    return res;}
};