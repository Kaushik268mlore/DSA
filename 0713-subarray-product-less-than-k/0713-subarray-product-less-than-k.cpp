class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0,cnt=0,prod=1;
        if(k<=0)return 0;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            while(prod>=k&&i>=j)prod/=nums[j++];
            cnt+=i-j+1;
            cout<<cnt<<endl;
        }
    return cnt;}
};