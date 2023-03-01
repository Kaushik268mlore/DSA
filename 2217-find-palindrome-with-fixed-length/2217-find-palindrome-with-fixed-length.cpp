class Solution {
public:
    // man i hate math and deriving a math eqn during a contest is the worst thing that can happen to a person
// I legit thought this had to be dealt with some string but NO this isnt fair... I'm dissapointed at this problem
    
    vector<long long> kthPalindrome(vector<int>& queries, int sz) {
        //votrubac's born with math 
    vector<long long> res;
    long long start = pow(10, (sz + 1) / 2 - 1), end = pow(10, (sz + 1 ) / 2), mul = pow(10, sz / 2);    
    for (int q : queries)
        res.push_back(start + q > end ? -1 : 
            (start + q - 1) * mul + reverse(start + q - 1, sz % 2));
    return res;
}
    int reverse(long long n, bool skip) {
    long long res = 0;
    for (n = skip ? n / 10 : n; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
};