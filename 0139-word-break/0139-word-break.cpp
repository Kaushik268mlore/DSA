class Solution {
public:
    bool f(string s,unordered_set<string>&ss,vector<int>&dp,int id){
        if(id==s.size())return true;
        if(dp[id]!=-1)return dp[id];
        for(int i=id;i<s.size();i++){
            if(ss.count(s.substr(id,i-id+1))&&f(s,ss,dp,i+1)){
                dp[id]=1;
                return true;
            }
        }
    return dp[id]=false;
    }
    bool wordBreak(string s,vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_set<string>ss(wordDict.begin(),wordDict.end());
        return f(s,ss,dp,0);
    }
};