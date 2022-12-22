class Solution {
public:
/*
    Initial an array of hashset tree, tree[i] contains all connected nodes to i.
Initial an array count, count[i] counts all nodes in the subtree i.
Initial an array of res, res[i] counts sum of distance in subtree i.

Post order dfs traversal, update count and res:
count[root] = sum(count[i]) + 1
res[root] = sum(res[i]) + sum(count[i])

Pre order dfs traversal, update res:
When we move our root from parent to its child i, count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
res[i] = res[root] - count[i] + N - count[i]

return res, done.
*/
    // int N=10000;
     vector<int>ans;
     vector<int>cnt;
    vector<unordered_set<int>>tree;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        ans.assign(n, 0);
        cnt.assign(n, 1);
        for(auto i :edges){
             tree[i[1]].insert(i[0]);
            tree[i[0]].insert(i[1]);
        } 
        dfs(0,-1);
        dfs2(0,-1);
        return ans;
        
    }
    void dfs(int root,int prev){//preorder dfs to get the count the number of nodes of s subtree 'i'
        for(auto i:tree[root]){
            if(i==prev)continue;
            dfs(i,root);//check for the no.of nodes from i as well.
            cnt[root]+=cnt[i];
            ans[root] += ans[i]+cnt[i];
        }
    }
    void dfs2(int root,int prev){
        for(auto i:tree[root]){
            if(i==prev)continue;
            ans[i]=ans[root]-cnt[i]+cnt.size()-cnt[i];
            dfs2(i,root);
        }
    }
};