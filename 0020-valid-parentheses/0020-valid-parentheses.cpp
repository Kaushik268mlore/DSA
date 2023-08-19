
class Solution {
public:
bool check(char a,char b){
    if(a=='('&&b==')'||a=='['&&b==']'||a=='{'&&b=='}')return true;
    return false;
}
   bool isValid(string s) {//we'll be using stack to track the parenthesis in the  string 
   stack<char>st;
       for(int i=0;i<s.length();i++){
           if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
           else if(st.empty()||!check(st.top(),s[i]))return false;
           else st.pop();
       }
    return st.empty();
   }
};