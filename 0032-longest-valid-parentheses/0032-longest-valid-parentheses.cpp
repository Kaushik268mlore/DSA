class Solution {
public:
   
    int longestValidParentheses(string s) {//o(n) dp  solution
        s = ")" + s;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2];
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }
};