class Solution {
public:
    int minLength(string s) {
        // unordered_map<int,int>m;
        // int n=s.length();
        // while(s.find("AB")!=string::npos||s.find("AB")!=string::npos){
        //     auto iA=s.find("AB");
        //     auto iC=s.find("CD");
        //     if(iA<iC)s.erase(iA,2);
        //     else s.erase(iC,2);
        // }
        // // cout<<n<<endl;
        // // cout<<m[0]<<" "<<m[1]<<"\n";
        // // int res=n-(m[0]*2+m[1]*2);
        // return s.length();
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(st.empty())st.push(c);
            else {
                int last=st.top();
                if(c=='B'||c=='D'){
                    if(c=='B'){
                        if(last=='A')st.pop();
                        else st.push(c);
                    }
                    else if(c=='D'){
                        if(last=='C')st.pop();
                        else st.push(c);
                    }
                }
                else st.push(c);
            }
        }
        return st.size();
    }
};