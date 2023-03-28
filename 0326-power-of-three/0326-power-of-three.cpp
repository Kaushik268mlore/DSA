class Solution {
public:
    // bool isPowerOfThree(int num) {//this solution works for all the prime numbers
    //     int max3=pow(3,floor(log(INT_MAX)/log(3)));
    //     return num>0 and max3%num==0;
    // }
     bool isPowerOfThree(int n){
         if(n==1)return true;
         if(n==0||n%3!=0)return false;
         return   isPowerOfThree(n/3);
     }
};


