class Solution {
public:
    // int nextGreaterElement(int n) {
    //     string num=to_string(n);
    //     next_permutation(num.begin(),num.end());
    //     int res=stoll(num);
    //     return res>INT_MAX||res<=n?-1:res;
    // }
// LOL the above solution would certainly work, but the interviewer's instant follow up question would be to implement next_permutation
    // in that case
    int nextGreaterElement(int n) {
        string num=to_string(n);
        nexxt(num);
        int res=stoll(num);
        return res>INT_MAX||res<=n?-1:res;
    }
    bool nexxt(string& nums) {
        if(nums.empty()) return false;
        int i=nums.size()-1;
        while(i>=1 && nums[i]<=nums[i-1]) i--;
        if(i==0) return false; // no next permutation, i.e. already largest
        
        int j=nums.size()-1;
        while(nums[j]<=nums[i-1]) j--;
        swap(nums[i-1],nums[j]);
        
        reverse(nums.begin()+i,nums.end());
        return true;
    }
};