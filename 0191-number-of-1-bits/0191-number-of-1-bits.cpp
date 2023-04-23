class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t x=n;
        int cnt=0;
        while(x){
            x&=(x-1);
            cnt++;
        }
    return cnt;
    }
};