class Solution {
private :
//     double helper(double x,int n){       //my approach 
//         double subprod=helper(x,n/2);
//         if(n&1)return subprod*subprod*x;
//         return subprod*subprod;
//     }
// public:
//     double myPow(double x, int n) {
//        int sign=(n<0)?-1:1;
//        double res= helper(x,abs(n));
//         if(sign==-1)return 1.0/res;
//         return res;
//     }
    public: 
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x,n/2);
        
        }else{
            return x*myPow(x*x,n/2);
        }
    }
};