class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        for( auto a:edges){
            vis[a[1]]=1;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(!vis[i])res.push_back(i);
        }
    return res;
    }
};