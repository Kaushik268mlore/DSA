class Solution {
private:
    void dfs(vector<vector<int>>&al,int node,vector<int>&vis){
        vis[node]=1;
        for(int edges:al[node]){
            if(!vis[edges]){
                dfs(al,edges,vis);
            }
        }
    }
public:
    //apparently we have to count the connected parts and then return count-1, because that's all that'll take for connecting the other components.
    //traversals (bfs/dfs) is enough to calculate the connected components.
    //actually pretty standard graph problem 
    int makeConnected(int n, vector<vector<int>>& connections) {
        int w=connections.size();
        if(w<n-1)return -1;
        vector<vector<int>>al(n);
        for(auto comps:connections){
            al[comps[0]].push_back(comps[1]);
            al[comps[1]].push_back(comps[0]);
        }
        int cnt=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(al,i,vis);
            }
        }
    return cnt-1;}
};