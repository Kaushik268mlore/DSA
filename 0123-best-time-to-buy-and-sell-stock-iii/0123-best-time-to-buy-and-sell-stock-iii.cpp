class Solution {
public:
// okay so apparently the prorblem is to be solved using DP and most likely I'm guessing linear DP.
//     Edit: it insn't
//[3,3,4,0,0,3,1,4]
//so for every day at of the stock price , we have 3 options, buy sell and skip, depending on whether we are at the
//bought state or not
//DP memoization problem with multidimensional array 
    vector<vector<vector<int>>>mem;
    int recursion(vector<int>&p,int ind,int t,bool bought){
        if(ind>=p.size()||t==0)return 0;
        if(mem[bought][t][ind]!=-1)return mem[bought][t][ind];
        int result=recursion(p,ind+1,t,bought);//this is skip
        if(bought){
            result=max(result,recursion(p,ind+1,t-1,false)+p[ind]);//sell
        }
        else {
            result=max(result,recursion(p,ind+1,t,true)-p[ind]);//buy 
        }
        return mem[bought][t][ind]=result;
    }
    int maxProfit(vector<int>& prices) {
        mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        return recursion(prices,0,2,0);
    }
};