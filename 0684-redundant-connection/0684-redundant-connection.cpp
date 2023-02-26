class Solution {
public:
    // a very good DSU problem https://www.youtube.com/watch?v=1e67mQ-yBgE&t=0s refer if doubtful.
    int find(int x,vector<int>&arr){
        if(arr[x]==x)return x;
        return find(arr[x],arr);
    }
    void union_(int a,int b,vector<int>&arr){
        a=find(a,arr);
        b=find(b,arr);
        arr[a]=b;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n=e.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;//intitially everyone's their own parent.
        for(auto arr:e){
            if(find(arr[0],parent)==find(arr[1],parent))return arr;//the edge with the same parent is the redundant edge
            union_(arr[0],arr[1],parent);
        }
    return {};}
};