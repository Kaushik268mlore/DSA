class Solution {
public:
    bool judgeSquareSum(int c) {
      long long int l=0,r=sqrt(c);
        while(l<=r){
            if(l*l+r*r<c){l++;}
            else if(l*l+r*r>c){r--;}
            else return true;
        }
    return false;}
};