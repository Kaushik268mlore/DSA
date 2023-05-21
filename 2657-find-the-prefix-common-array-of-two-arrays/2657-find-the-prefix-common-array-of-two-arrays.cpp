class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>res(A.size());
//         vector<unordered_set<int>>vs;
        int cnt=0;
        vector<int>vis(A.size()+1);
        for(int i=0;i<A.size();i++){
            vis[A[i]]++;
            if(vis[A[i]]==2)cnt++;
            vis[B[i]]++;
            if(vis[B[i]]==2)cnt++;
            res[i]=cnt;
        }
   return res; }
};