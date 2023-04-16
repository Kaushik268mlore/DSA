class Solution {
public:
    // pretty simple linear DP problem, only thing is every time also subtract the transaction fee
    //we have two choices to either hold or sell
    // and if sold we buy again
    // this is a one pass solution
    int maxProfit(vector<int>& prices, int fee) {
        int sell=0,hold=INT_MIN;
        for(int lp:prices){
            int temp=sell;
            sell=max(sell,hold+lp);
            hold=max(hold,temp-lp-fee);
        }
    return sell;}
};