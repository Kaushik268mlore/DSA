class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)return nums;
        vector<int>res(n,-1);
        if(2*k+1>n)return res;
        vector<long long>pre(n+1);
        for(int i=0;i<n;i++)pre[i+1]+=nums[i]+pre[i];
        for(int i=k;i+k<n;i++){
            // if(i==k)res[i]=(nums[i+k])/(2*k+1);
            res[i]=(pre[i+k+1]-pre[i-k])/(2*k+1);
        }
        return res;
    }
};