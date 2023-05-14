#define LL long long 
class Solution {
public:
//     I knew this wouldd be a prefix based problem ...lol
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1),suff(n+1);
        pre[0]=0,suff[n]=0;
        for(int i=0;i<n;i++)pre[i+1]=pre[i]|nums[i];
        for(int i=n-1;i>=0;i--)suff[i]=nums[i]|suff[i+1];
        LL f=1<<k;
        LL res=0;
        for(int i=0;i<n;i++){
            res=max(res,pre[i]|(nums[i]*f)|suff[i+1]);
        }
        return res;
    }
};