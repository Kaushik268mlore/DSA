class Solution {
public:
    void helper(int k,int n,vector<int> &curr,set<vector<int>> &set,int idx){
        //base case(the case in which we will get our answer)
        //we will get our answer when n==0
        //if k==0 then we have exhausted the limit of elements simply backtracking(in case n==0) and look for another combination
        if(k==0 and n!=0){
            return;
        }
        if(n==0){
            set.insert(curr);
            return;
        }
        for(int i=idx;i<=9;i++){
            curr.push_back(i);
            helper(k-1,n-i,curr,set,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        set<vector<int>> set;
        helper(k,n,curr,set,1);
        for(auto it:set){
            if(it.size()==k){
                res.push_back(it);
            }
        }
        return res;
    }
};