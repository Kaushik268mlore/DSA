class Solution {
public:
    //by the looks of this , it looks like a graph problem
    //just returning the minimum path length won't give the right answer, because we have to consider 
    // so just traversing throughout the graph and maintaining the minimum score is enough .
    int minScore(int n, vector<vector<int>>& roads) {
        //create an adjacency matrix
        vector<vector<pair<int,int>>>mat(n+1);
        for(auto road:roads){
            mat[road[0]].push_back({road[1],road[2]});
            mat[road[1]].push_back({road[0],road[2]});
        }
        vector<bool>vis(n+1);
        int res=INT_MAX;
        dfs(1,mat,vis,res);
        return res;
    }
    void dfs(int node,vector<vector<pair<int,int>>>&mat,vector<bool>&vis, int &res){
        vis[node]=1;
        for(auto edge:mat[node]){
            res=min(res,edge.second);
            if(!vis[edge.first]) dfs(edge.first,mat,vis,res);
        } 
    }
};