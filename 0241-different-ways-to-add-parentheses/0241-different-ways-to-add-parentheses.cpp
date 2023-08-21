class Solution {
public:
    // vector<int>res;
    bool isop(string s,int i,int j){
        for(int k=i;k<=j;k++){
            if(s[k]=='+'||s[k]=='-'||s[k]=='*')return 1;
        }
    return 0;
    }
    // int do_op()
    vector<int> helper(string s,int start,int end){
        if(!isop(s,start,end)){
            return {stoi(s.substr(start,end+1))};
        }
        vector<int>ans;
        for(int i=start;i<=end;i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                vector<int>first=helper(s,start,i-1);
                vector<int>second=helper(s,i+1,end);
                for(auto c:first)cout<<c<<" ";
                for(auto c:second)cout<<c<<" ";
                for(int j=0;j<first.size();j++){
                    for(int k=0;k<second.size();k++){
                            int res;
                            if(s[i]=='+'){
                                res=first[j]+second[k];
                            }
                            else if(s[i]=='-')res=first[j]-second[k];
                            else if(s[i]=='*')res=first[j]*second[k];
                        cout<<res<<" ";
                        ans.push_back(res);
                    }
                    
                }
            }
        }
    return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        if(exp.length()==1)return {exp[0]-'0'};
        return helper(exp,0,exp.length()-1);
    }
};