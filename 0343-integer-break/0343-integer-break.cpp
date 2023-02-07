class Solution {
public:
    /* int integerBreak(int n) { // math based solution,because we can maximise it with the number of 3s and 2s
        if(n==2)return 1;
        if(n==3)return 2;
        int two=0;
        int three=n/3;
        if(n%3==1)
        {
            three--;
        }
        two= (n-three*3)/2;
        
        return fastexpo(3,three)*fastexpo(2,two);
        
    }
    
    long long fastexpo(long long a,long long n){
    int apb=1;
    while(n>0){
        
        if(n&1){//checks if the the ith bit is 1.. if 1 then it'll multiply the value of a.
            apb*=a;
        }
        a*=a;
        n>>=1;
    }
    return apb;
} */
    
    int integerBreak(int n){ //linear DP solution aka caching 
        vector<int>dp(100);//dp[i] stores the maximum value of (product of breaks of the integer i)
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        for(int i=4;i<=n;i++){
            int num=i;
            for(int j=1;j<=num;j++){
               int x=j;
                int y=num-j;
                dp[i]=max({x*y,dp[i],dp[x]*y,x*dp[y],dp[x]*dp[y]});
            }
        }
       return dp[n]; 
    }
};