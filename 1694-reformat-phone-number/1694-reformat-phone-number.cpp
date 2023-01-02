class Solution {
public:
    string reformatNumber(string s) {
    string t,ans;
    for(char c:s){
        if(isdigit(c))t+=c;
    }
    int len=t.length();
    while(len){
        if(len>4||len==3){
            ans+=t.substr(0,3);
            t.erase(0,3);
            ans+='-';
            len-=3;
        }
     if(len==2||len==4){
            ans+=t.substr(0,2);
            t.erase(0,2);
            ans+='-';
            len-=2;
        }}
        ans.pop_back();
        return ans;
    }
};