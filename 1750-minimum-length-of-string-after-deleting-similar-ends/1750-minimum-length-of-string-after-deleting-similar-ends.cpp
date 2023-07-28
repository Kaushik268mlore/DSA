class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int l=0,r=n-1;
        while(l<r&&s[l]==s[r]){
            char ch=s[l];
            if(s[r]!=s[l])break;
            while(l<=r&&s[l]==ch)l++;
            while(l<=r&&ch==s[r])r--;
        }
    return r-l+1;
    }
};