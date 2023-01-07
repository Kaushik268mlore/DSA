class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//this is vertical or column traversal
       string ans="";
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
    return ans;}
};