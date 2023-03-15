class Solution {
public:
    bool isIsomorphic(string s, string t) {
    return helper(s,t) and helper(t,s);}
    bool helper(string s,string t){
        int n=s.length();
        unordered_map<char,char>map;
        for(int i=0;i<n;i++){
            if(map.find(s[i])!=map.end()){
                if(map[s[i]]!=t[i])return false;}
            else {map[s[i]]=t[i];}
        }
        return true;
        
    }
};