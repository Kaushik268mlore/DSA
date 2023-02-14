class Solution {
public:
    //vector<int>dp(11,0);
    int countNumbersWithUniqueDigits(int n) {
        //iterative dp problem
        if(n==0)return 1;
        if(n>10)n=10;
        int res=10,fact=9;
        for(int i=1;i<n;i++){
            fact*=(10-i);
            res+=fact;
        }
    return res;}
};