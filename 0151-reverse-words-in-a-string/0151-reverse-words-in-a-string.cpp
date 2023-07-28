class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string words;
        stack<string>st;
        while(is>>words){
            st.push(words);
        }
        string res="";
        while(st.size()){
            res+=st.top();
            res+=" ";
            st.pop();
        }
        res.pop_back();
        return res;
    }
};