class Solution {
public:
    // "ADOBECODEBANC"
    // "ABC"
    string minWindow(string s, string t) {
    unordered_map<char,int>map;
        for(char c:t)map[c]++;
        int j=0, st=0,len=INT_MAX;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]>0)cnt++;
            map[s[i]]--;
            if(cnt==t.length()){
                while(j<i&&map[s[j]]<0)map[s[j++]]++;
                if(len>i-j){
                    st=j;
                    len=i-j+1;
                }
                map[s[j++]]++;
                cnt--;
            }
        }
     if(len==INT_MAX)return "";
    return s.substr(st,len);
    }
};