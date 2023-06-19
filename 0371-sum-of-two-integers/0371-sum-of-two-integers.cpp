class Solution {
public:
//     okay, without using +/- is kinda hard
    
     int getSum(int a, int b) {
        int sum = a;
        uint32_t carry = b; // unsigned int substitutes for the extra sign bit in case of the negative integers overflow
        while(carry){
            sum = a^carry;
            carry = (a&carry)<<1;
            a = sum;
        }
        return sum;
    }
};