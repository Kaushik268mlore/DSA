class Solution {
public:
    //a normal dfs will work.
    vector<vector<int>>res;
    void dfs(int s,int d,vector<vector<int>>&adj,vector<int>rt){
        rt.push_back(s);
        if(s==d){
            res.push_back(rt);
            // rt.clear();
            return;
        }
        for(int i=0;i<adj[s].size();i++){
            dfs(adj[s][i],d,adj,rt);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==0)return {};
        vector<int>rt;
        dfs(0,n-1,graph,rt);
        return res;
    }
};