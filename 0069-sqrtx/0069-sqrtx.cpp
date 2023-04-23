#define LL long long
class Solution {
public:
    int mySqrt(int x) {
        LL n=x;
        LL i;
        for(i=1;i*i<=n;++i);
        return i-1;
    }
};