class Solution {
public:
    // pretty similor to coloring maps problem
     void dfs(int v,vector<vector<int>>&adj,vector<int>&result) {
        vector<bool> used(5,0);
        
        for(int i=0;i<adj[v].size();i++) 
            used[result[adj[v][i]]] =1; 
        
        for(int k=1;k<5;k++) { //there are only 4 plants labelled from 1 to 4
            if(!used[k]) //use the 1st available color that is not used by any of the neighbours 
            {
                result[v] = k;
                break;
            }
        }
        //Now find plant for it's neighbouring gardens
        for(int i=0;i<adj[v].size();i++) 
            if(!result[adj[v][i]])
                dfs(adj[v][i],adj,result);
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(int i=0;i<paths.size();i++) 
        {
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        vector<int> result(n,0);
        for(int i=0;i<n;i++) 
            if(!result[i])
                 dfs(i,adj,result);
        
        return result;
    }
};