class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
//         char,freq;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(st.empty()||st.top().first!=s[i])st.push({s[i],1});
            else{
                st.top().second++;
                if(st.top().second==k)st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++)res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};