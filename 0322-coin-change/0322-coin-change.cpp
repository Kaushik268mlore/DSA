class Solution {
public:
    /*so this is a top down approach where we calculate the necessary coins needed for every number till amt 
    the recursive case is need(i)=min(need(i),need(i-coins[i]))
    as we iterate through all the coins 
    this is a very standard and  famous problem in DSA*/
    int coinChange(vector<int>&arr, int amt) {
        vector<int>dp(amt+1,amt+1);
        dp[0]=0;//base case
        sort(arr.begin(),arr.end());
        for(int i=1;i<=amt;i++){
            for(int j=0;j<arr.size();j++){
                if(i-arr[j]>=0){
                    dp[i]=min(dp[i],dp[i-arr[j]]+1);
                }
            }
        }
    return (dp.back()!=amt+1)?dp.back():-1;
    }
};