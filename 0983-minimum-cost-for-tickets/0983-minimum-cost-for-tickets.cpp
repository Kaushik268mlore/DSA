class Solution {
private:
//     int helper(int i){
        
//     }
public:
    //definitely seems like a linear DP problem
    // dp(i)=min(dp(i+1)+costs[0],dp(i+7)+costs[1],dp(i+30)+costs[2]) is the recursive relation , to check if any day in the year is being travelled, its better to hash it as the fetch will be in o(1) .
    //iterative dp

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366);
        unordered_set<int>s(days.begin(),days.end());
        for(int i=1;i<=365;i++){
            if(s.find(i)==s.end())dp[i]=dp[i-1];
            else {
                dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[365];
    }
};