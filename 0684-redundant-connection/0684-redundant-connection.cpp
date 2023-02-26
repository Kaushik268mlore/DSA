class Solution {
public:
    // a very good DSU problem https://www.youtube.com/watch?v=1e67mQ-yBgE&t=0s refer if doubtful.
    int find(int x,vector<int>&arr){
        if(arr[x]==x)return x;
        return arr[x]=find(arr[x],arr);
    }
    void union_(int a,int b,vector<int>&arr,vector<int>&rank){
        a=find(a,arr);
        b=find(b,arr);
        //below lines are the optimisation
        if(rank[a]>rank[b]){
            arr[b]=a;
            rank[a]+=rank[b];
        }
        else{
            arr[a]=b;
            rank[b]+=rank[a];
        }
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
    //     int n=e.size();      //this solution is normal DSU 
    //     vector<int>parent(n+1);
    //     for(int i=1;i<=n;i++)parent[i]=i;//intitially everyone's their own parent.
    //     for(auto arr:e){
    //         if(find(arr[0],parent)==find(arr[1],parent))return arr;//the edge with the same parent is the redundant edge
    //         union_(arr[0],arr[1],parent);
    //     }
    // return {};
    // below we have a slight optimisation , we add another array called rank that stores data of each node's children
        // the idea is to choose the parent with more number of children 
        int n=e.size();
        vector<int>par(n+1);
        vector<int>rank(n+1);
        for(int i=1;i<=n;i++)par[i]=i,rank[i]=1;
        for(auto arr:e){
            if(find(arr[0],par)==find(arr[1],par))return arr;//the edge with the same parent is the redundant edge
            union_(arr[0],arr[1],par,rank);
        }
            
    return {};}
};