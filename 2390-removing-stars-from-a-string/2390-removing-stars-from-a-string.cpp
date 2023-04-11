class Solution {
public:
    string removeStars(string s) {
        string res;
        for(char c:s){
            if(c=='*'||c=='!'||c=='@'||c=='#'||c=='$'){
                res.pop_back();
            }
            else res+=c;
        }
        return res;
        
    }
};