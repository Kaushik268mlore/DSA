class Solution {
public:
    bool canConstruct(string s, int k) {// simple problem
       vector<int>map(26,0);
        if(k>s.length())return false;
        for(char c:s){
            map[c-'a']++;
        }
        int cnt=0;
        for(int x:map){
            if(x&1)cnt++;
        }
        return (cnt>k)?false:true;
    }
};