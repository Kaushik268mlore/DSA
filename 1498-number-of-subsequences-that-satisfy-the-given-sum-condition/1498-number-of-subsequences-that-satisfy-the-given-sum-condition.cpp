#define LL long long
// TLE SOLUTION
// class Solution {
// public:
//     const int mod=1e9+7;
//     int numSubseq(vector<int>& nums, int target) {
//         LL n=nums.size();
//         LL cnt=0;
//         for(LL i=0;i<1<<n;i++){
//             LL cs=0;
//             int minn=INT_MAX,maxx=INT_MIN;
//             for(LL j=0;j<n;j++){
//                 if(i&(1<<j)){
//                     minn=min(minn,nums[j]);
//                     maxx=max(maxx,nums[j]);
//                 }
//             }
//                 if(minn+maxx<=target)(cnt++)%mod;
//         }
//     return (cnt-1)%mod;}
// };
class Solution{
    private:
    int exp(LL a,LL b,LL mod){
        int res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%mod;
                // res%=mod;
            }
            b>>=1;
            a=(a*a)%mod;
        }
    return res%mod;}
 public:
    // okay i find this problem really cool and conceptual
    const LL mod=1e9+7;
    int numSubseq(vector<int>&nums,int t){
        sort(nums.begin(),nums.end());
        int cnt=0;
        int n=nums.size();
        // I mean just watch how cool the 2 pointer solution is!!! I'm having a codegasm..lol
        int l=0,r=n-1;
        // for(int i=0;i<n;i++){
        //     while(nums[l]+nums[r]>t&&i<=r)r--;
        //     if(i<=r){
        //         LL poss=exp(2,r-i,mod);
        //         poss%=mod;
        //         cnt+=poss;
        //         cnt%=mod;
        //     }
        while(l<=r){
            if(nums[l]+nums[r]<=t){
                cnt+=(exp(2,r-l,mod));
                cnt%=mod;
                l++;
            }
            else r--;
        }
        
    return cnt%mod;}
};