class Solution {
public:
    vector<vector<int>>res;
    void backtrack(int num,int n,int k,vector<int>&curr){
        if(num>n)return;
        if(curr.size()==k)res.push_back(curr);
        curr.push_back(num+1);
        backtrack(num+1,n,k,curr);
        curr.pop_back();
        backtrack(num+1,n,k,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        backtrack(0,n,k,curr);
        set<vector<int>>s(res.begin(),res.end());
        return vector<vector<int>>(s.begin(),s.end());
    }
};