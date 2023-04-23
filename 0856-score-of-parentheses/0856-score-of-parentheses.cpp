class Solution {
public:
    // again an edge case issue
    int scoreOfParentheses(string s) {
//         stack<int>st;
//         int i=0;
//         int res=0;
//         int mul=0;
//         while(i<s.length()){
//             while(s[i]=='('){
//                 mul++;
//                 i++;
//             }
//             res+=pow(2,mul);
//             while(s[i]==')'){
//                 mul--;
//                 i++;
//             }
        
//     return res;
//     }
     int depth = 0, res = 0;
        char prev = '(';
        
        for (const char &ch: s) {
            if (ch == '(') {
                depth++;
            } else {
                depth--;
                if (prev == '(')
                    res += 1<<depth;   //changed this part
            }
            
            prev = ch;
        }
        
        return res;
    }
};
// "(()(()))" 6