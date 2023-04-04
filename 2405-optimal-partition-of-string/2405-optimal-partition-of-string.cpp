class Solution {
public:
    //very simple hashing problem
    int partitionString(string s) {
        int cnt=0;
        unordered_map<int,int>m;
        for(char c:s){
            if(m[c-'a']==1){
                cnt++;
                m.clear();
                m[c-'a']++;
            }
            else m[c-'a']++;
        }
    return ++cnt;}
};