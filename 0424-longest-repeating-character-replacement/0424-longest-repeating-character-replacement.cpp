class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(),maxfreq=0,ans=0,j=0;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            maxfreq=max(maxfreq,m[s[i]]);
            while(i-j+1-maxfreq>k){
                m[s[j]]--;
                j++;
            }
            ans=i-j+1;
        }
    return ans;}
};