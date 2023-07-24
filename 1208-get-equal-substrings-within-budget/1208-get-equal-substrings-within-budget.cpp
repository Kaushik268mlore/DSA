class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n=s.length(),i=0,j=0,ans=0;
        int e=0;
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            e+=abs(s[i]-t[i]);
            while(e>k){e-=abs(s[j]-t[j]);j++;}
            ans=max(ans,i-j+1);
        }
    return ans;
    }
};