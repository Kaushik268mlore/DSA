class Solution {
public:
    // okay so this is a connected components problem and here every time we call the dfs/bfs we cover an island
    // and here we're not using any extra space for the visited node , instead we assign the value 2 for the visited       //nodes in the given problem.
    int numIslands(vector<vector<char>>& v) {
        int res=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]=='1'){
                    dfs(v,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>&v,int i,int j){
        if(i<0||i>=v.size()||j<0||j>=v[0].size()){
            return;
        }
        if(v[i][j]=='0'||v[i][j]=='2'){
            return;
        }
        v[i][j]='2';
        dfs(v,i+1,j);
        dfs(v,i,j-1);
        dfs(v,i-1,j);
        dfs(v,i,j+1);
    }
};