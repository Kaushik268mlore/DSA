class Solution {
public:
    //  i thought we might need some hashing to be done , but looking at the constraints,it seems that we can go with n2 solution
    // int numIdenticalPairs(vector<int>& nums) {
    //     // unordered_map<int,vector<int>>m;
    //     // for(int i=0;i<nums.size();i++){
    //     //     m[nums[i]].push_back(i);
    //     // }
    //     int n=nums.size(),cnt=0;
    //     for(int i=0;i<n;i++ ){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]==nums[j])cnt++;
    //         }
    //     }
    // return cnt;}
    //now an O(n) solution using hashmap.
    int numIdenticalPairs(vector<int>& nums){
        unordered_map<int,int>m;
        int cnt=0;
        for(int id:nums){
            m[id]++;
        }
        for(auto [k,v]:m){
            cnt+=(v*(v-1)/2);
        }
    return cnt;}
};