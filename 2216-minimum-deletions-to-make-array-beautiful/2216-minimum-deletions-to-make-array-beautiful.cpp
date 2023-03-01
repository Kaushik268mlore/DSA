class Solution {
public:
    // int minDeletion(vector<int>& nums) {//totally wrong approach for the problem ..lol
    //     multiset<pair<int,int>>s;
    //     for(int i=0;i<nums.size();i++){
    //         s.insert({i,nums[i]});
    //     }
    //     for(auto &[i,p]:s){
    //         if(i%)
    //     }
    // }
    int minDeletion(vector<int>& nums){// pretty easy question just that the writings are made overcomplicated
        // here we keep track of the number of deletions to be made , which would only be when nums[i]==nums[i+1]
        if(size(nums)==1)return 1;
        int del=0;
        for(int i=0;i-del+1<size(nums);i+=2){
            del+=(nums[i-del]==nums[i-del+1]);
        }
        return (size(nums)-del)%2+del; 
            //then in the end we also gotta check if the final array
//size is even or not , if not reduce one element from the end and make it even 
        // U see it actually means u gotta calculate the number of deletions to be done so that u can have an even sized distinct array ..
    }
};