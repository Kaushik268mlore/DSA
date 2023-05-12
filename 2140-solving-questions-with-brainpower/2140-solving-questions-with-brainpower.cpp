#define LL long long
class Solution {
public:
    // recursive DP for sure... and a very traditional one of making choices..
    // LL dp[100001];
    LL  rec(vector<vector<int>>&q,int idx,vector<LL>&dp){
    if(idx>=q.size())return 0;
    if(dp[idx]!=-1)return dp[idx];
    LL points=q[idx][0];
    LL postskipidx=q[idx][1]+idx+1;
    LL choose=points+rec(q,postskipidx,dp);
    LL skip=rec(q,idx+1,dp);
    return dp[idx]=max(choose,skip);//checking max(skipping and not skipping possibilities).
    }
    long long mostPoints(vector<vector<int>>&q) {
        int n=q.size();
        vector<LL>dp(n+1,-1);
        // memset(dp,-1,n+1);
        return rec(q,0,dp);
    }
};