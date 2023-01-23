class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int N=s.length();
        int sum=0;
        for(int i=0;i<N;i++){
            if(i&1)sum-=(s[i]-'0');
            else sum+=(s[i]-'0');
        }
        return sum;
    }
};