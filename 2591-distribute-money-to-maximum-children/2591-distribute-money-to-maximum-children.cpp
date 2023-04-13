class Solution {
public:
    // its kind of not clear what the requirements of the problem are... so 
    // this is greedy
    // int distMoney(int money, int children) {
    //     //we'll initially distribute 1 money to every kid , to meet the constraints
    //     money-=children;
    //     if(money<0)return -1;
    //     if(money%7==0&&(money/7)==children)return children;
    //     if(money%7==3&&money/7==(children-1))return children -2;//then we analyse the test cases
    //     return min(children-1,money/7);
    // }
    // this is a binary search solution
     bool check(int x,int m,int n){
        if(x*8>m)return false;
        
        m-=x*8;
        
        if(m<(n-x))return false;
        if(n-x==1 && m == 4)return false;
        if(n-x == 0 && m)return false;
        return true;
    }
    
    int distMoney(int money, int n) {
        int l = -1,r = n+1;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,money,n))l = m;
            else r = m;
        }
        return l;
    }
};