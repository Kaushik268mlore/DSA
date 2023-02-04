class Solution {
public:
    /*vector<int> countBits(int n) {//a very easy math implementation,but can also be done using DP.
      vector<int>arr;
      for(int i=0;i<=n;i++){
          arr.push_back(__builtin_popcount(i));
      }
    return arr;}*/
    vector<int> countBits(int n) {//and this is the dp solution ,and solving it using DP aint easy..
        vector<int>dp(n+1,0);
        int off=1;
        for(int i=1;i<=n;i++){
            if(off*2==i)off=i;
            dp[i]=1+dp[i-off];
        }
    return dp;}
};