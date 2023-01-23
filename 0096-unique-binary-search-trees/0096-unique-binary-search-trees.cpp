class Solution {
public:
    int numTrees(int n) {           //catalan numbers solution
                long ans = 1;
        for(int i = 1; i < n; i++)  
            ans = ans*(n+i+1) / i;    // do note that numerator and denominator will always be divisible
        return ans / n;
    }
};