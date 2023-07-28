class Solution {
public:
//     a really nice two pointer problem...
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int>perm(n+1);
        int l=0,r=n;
        for(int i=0;i<n;i++){
            if(s[i]=='I')perm[i]=l++;
            else perm[i]=r--;
        }
        perm[n]=l;
        return perm;
    }
};