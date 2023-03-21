class Solution {
public:
    //here the no.of zeroes is the only thing that matters along with how many occur consecutively, 
    // long long zeroFilledSubarray(vector<int>& nums) {
    //     long long ans=0,cnt=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]==0)cnt++;
    //         else cnt=0;
    //         ans+=cnt;
    //     }
    // return ans;}
    //pretty much the same logic but done using 2 pointers
    
    long long zeroFilledSubarray(vector<int>& nums){
        long long int s=0,e=0,ans=0;
        for(s=0,e=0;e<nums.size();e++){
            if(nums[e]!=0)s=e+1;
            ans+=(e-s+1);
        }
    return ans;}
};