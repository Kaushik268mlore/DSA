#define LL long long
class Solution {
public:
    // int n;
    // LL f(int x,bool par,vector<int>nums,vector<vector<LL>>&dp,int id){
    //     if(id>=n)return 0;
    //     if(dp[id][par]!=-1)return dp[id][par];
    //     // int ele=nums[id]; // this bastard was giving an error, because in the recursive tree , this will make the wrong calls , it won't consider the nums[id], instead it will choose the ele value itself ,because its not passed through reference
    //     LL yes=0,no=f(x,par,nums,dp,id+1);
    //     if(nums[id]%2==par){
    //         yes=nums[id]+f(x,par,nums,dp,id+1);
    //     }
    //     else yes=nums[id]-x+f(x,nums[id]&1,nums,dp,id+1);
    //     return dp[id][par]=max(yes,no);
    // }
    // long long maxScore(vector<int>& nums, int x) {
    //     n=nums.size();
    //     vector<vector<LL>>dp(n,vector<LL>(2,-1));
    //     return nums[0]+f(x,nums[0]&1,nums,dp,1);
    // }
     long long helper(int index,int p, vector<int>&nums,int x,vector<vector<long long>>&dp){
        int n= nums.size();
        if(index>=n) return 0;
        if(dp[index][p]!=-1) return dp[index][p];
        long long take=0;
        long long nottake=0;
        nottake= helper(index+1,p,nums,x,dp);
        if(nums[index]%2==p){
            take= nums[index]+helper(index+1,p,nums,x,dp);
        }
        else{
            take= nums[index]-x + helper(index+1,nums[index]%2,nums,x,dp);
        }
        return dp[index][p]= max(take,nottake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n= nums.size();
        int p= nums[0]%2;
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return nums[0]+ helper(1,p,nums,x,dp);
        
    }
};