class Solution {
public:
    //a simple implementation
    bool checkDistances(string s, vector<int>& arr) {
       unordered_map<int,vector<int>>m;
        for(int i=0;i<s.length();i++){
            m[s[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;i++){
            if(m.find(i)!=m.end()){
                auto v=m[i];
                if(arr[i]!=abs(v[0]-v[1])-1)return false;
            }
        }
    return true;}
};