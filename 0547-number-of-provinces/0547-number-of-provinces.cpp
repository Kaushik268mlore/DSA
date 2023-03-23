class Solution {
private:
    // a good problem where we count the connected graphs and just return the count , this can be checked by seeing //if the node is traversed or not and adding a count whenever a non neighbouring node traversal starts its traversal
    int cnt=0;
    void dfs(vector<int>&vis,int node,vector<vector<int>>&adj){
        vis[node]=1;
        for(int edges:adj[node]){
            if(!vis[edges]){
                
                dfs(vis,edges,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>al(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1&&i!=j){
                    al[i].push_back(j);
                    al[j].push_back(i);
                }                                      
            }
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                dfs(vis,i,al);
                cnt++;
            }
        }
    return cnt;
    }
};