class Solution {
public:
    vector<vector<string>>res;
    bool ispal(string s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--])return 0;
        }
    return 1;}
    void helper(string s,int start,vector<string>&curr){
        if(start>=s.length())res.push_back(curr);
        for(int i=start;i<s.length();i++){
            if(ispal(s,start,i)){
                curr.push_back(s.substr(start,i-start+1));//consider the current one
                helper(s,i+1,curr);
                curr.pop_back();//backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        helper(s,0,curr);
        return res;
    }
};