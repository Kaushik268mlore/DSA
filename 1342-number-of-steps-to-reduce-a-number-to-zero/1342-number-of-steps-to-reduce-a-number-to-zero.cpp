class Solution {
public:
    int numberOfSteps(int num) {
        int n=num;
        int cnt=0;
        while(n){
            cnt++;
            if(n&1)n--;
            else n>>=1;
        }
    return cnt;}
};