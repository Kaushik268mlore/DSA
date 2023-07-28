class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        for(int i=0;i<n;i+=2*k){
            int st=i,j=min(i+k-1,n-1);
            while(st<j){
                swap(s[st++],s[j--]);
            }
        }
        return s;
    }
};