class Solution {
public:
     int integerBreak(int n) {
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
} 
};