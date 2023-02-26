class Solution {
public:
    // a DSU implementation
    int find(int x,vector<int>&arr){
        if(arr[x]==x)return x;
        return arr[x]=find(arr[x],arr);//this is path compression where because of the nature of the problem we return its immediate parent
    }
    void union_(int a,int b,vector<int>&arr){
        a=find(a,arr);
        b=find(b,arr);
        arr[a]=b;
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        vector<bool>res;
        vector<int>parent(n+1);
        //if(t==0)return vector<bool>(queries.size(),true);
        for(int i=1;i<=n;i++)parent[i]=i;
        for(int i=t+1;i<=n;i++){//this logic is lit! cuz we consider the divisors greater than threshold and connect roads b/w aka make union among their multiples which lie in the range[1,n]
            int f=1;
            while(f*i<=n){
                union_(f*i,i,parent);
                f++;
            }
        }
        for(auto &q:queries){
            res.push_back(find(q[0],parent)==find(q[1],parent));
        }
    return res;}
};