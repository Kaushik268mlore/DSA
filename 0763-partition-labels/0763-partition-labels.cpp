class Solution {
public:
    vector<int> partitionLabels(string s) {//very brilliant smartass solution.
        vector<int>id(26),res;
        for(int i=0;i<s.length();i++){
            id[s[i]-'a']=i;
        }
        int j=0,k=0;
        for(int i=0;i<s.length();i++){
            j=max(j,id[s[i]-'a']);
            if(i==j){
                res.push_back(j-k+1);
                k=i+1;
            }
        }
    return res;}
};