class Solution {
public:
    //similar to combination IV
    int change(int amount, vector<int>& coins) {
        vector<unsigned int>dp(amount+1);
        dp[0]=1;
        for(int coin:coins){
            for(int i=1;i<=amount;i++){
                if(i>=coin)dp[i]+=dp[i-coin];
            }
        }
    return dp[amount];}
};