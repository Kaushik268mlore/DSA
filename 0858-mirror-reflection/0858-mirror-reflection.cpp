class Solution {
public:
    int mirrorReflection(int p, int q) {
       while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p % 2 + q % 2; 
    }
};
// This problem can be transformed into finding m * p = n * q. Here,
// m = the number of room extension + 1.
// n = the number of light reflection + 1.

// If the number of light reflection is odd (which means n is even), it means the corner is on the left-hand side. The possible corner is 2.
// Otherwise, the corner is on the right-hand side. The possible corners are 0 and 1.
// Given the corner is on the right-hand side.
// If the number of room extension is even (which means m is odd), it means the corner is 1. Otherwise, the corner is 0.
// So, we can conclude:

// m is even & n is odd => return 0.
// m is odd & n is odd => return 1.
// m is odd & n is even => return 2.