class Solution {
public:
    string sortVowels(string s) {
        vector<int>id;
        vector<char>cc;
        int n=s.length(),cnt=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='a'||c=='A'||c=='E'||c=='e'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U'){
                id.push_back(i);
                cc.push_back(s[i]);
                cnt++;
            }
        }
        if(cnt==0)return s;
        sort(cc.begin(),cc.end());
        string res=s;
        for(int i=0;i<cc.size();i++){
            res[id[i]]=cc[i];
        }
    return res;
    }
};