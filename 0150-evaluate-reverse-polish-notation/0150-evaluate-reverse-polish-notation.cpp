class Solution {
public:
    //lol RPN is same as evaluating a postfix notation
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i:tokens){
            if(i=="+"||i=="-"||i=="*"||i=="/"){
                int p1=st.top();
                st.pop();
                int p2=st.top();
                st.pop();
                if(i=="+")p1=p1+p2;
                if(i=="-")p1=p2-p1;
                if(i=="*")p1=p1*p2;
                if(i=="/")p1=p2/p1;
                st.push(p1);
            }
            else st.push(stoi(i));
        }
    return st.top();}
};