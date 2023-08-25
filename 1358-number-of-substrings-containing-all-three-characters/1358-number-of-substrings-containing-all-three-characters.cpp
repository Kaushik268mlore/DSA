class Solution {
public:
    int numberOfSubstrings(string s) {// amazing question on at least keyword
        int n=s.length(),cnt=0,l=0;
        vector<int>arr(3);
        for(int i=0;i<n;i++){//sliding window solution
            arr[s[i]-'a']++;
            while(l<n and arr[0] and arr[1] and arr[2]){
                arr[s[l]-'a']--;l++;
            }
            cnt+=l;
        }
    return cnt;}
};