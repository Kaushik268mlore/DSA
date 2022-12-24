class Solution {
public:// 2pointer solution
    bool isSubsequence(string s, string t) {
        int m=s.length(),n=t.length();
        int i=0,j=0;
        while(i<m and j<n){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }
};