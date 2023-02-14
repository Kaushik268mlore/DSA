class Solution {
public:
    int dp[10000]={0};
    int maxProfit(vector<int>& prices) {
//again iterative dp
        int n=size(prices);
        int selling=0,cooldown=0,buying=-prices[0];
        for(int i=0;i<n;i++){
            int prev=selling;
            selling =buying+prices[i];
            buying =max(cooldown-prices[i],buying);
            cooldown=max(cooldown,prev);
        }
    return max(cooldown,selling);}
};