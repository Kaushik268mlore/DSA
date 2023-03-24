class Solution {
public:
    //because we are given a directed graph we need to use a pair to denote the adjacency matrix
//     The caveat is that our edges are directed. To count the number of edges that are directed from a parent to its child node, we must traverse the entire tree. If there is an edge from a child to its parent node, we will be unable to reach the child from the parent.

// To traverse the entire tree, we must find a way to get from node 0 to all of the nodes in any case. This is possible if the edges are treated as undirected. We add an opposite edge from node b to node a for every given edge in connections from node a to node b. Let us refer to the edge we added as an "artificial" edge and the edge present in connections as an "original" edge.

// If we use an "artificial" edge to move from the parent node to the child node, we know that the original edge is directed from the child node to the parent node. We don't need to flip the "original" edge.

// If we use an "original" edge to move from the parent node to the child node, it means we need to flip this edge. Whenever we encounter such an edge, we will increment our answer variable by 1.

// We can distinguish between an "original" and an "artificial" edge in many different ways (assigning booleans, specific numbers, etc.). In this article, we will associate an extra value with each edge - 1 for "original" edges and 0 for "artificial" edges.

// We also set an answer variable count = 0 to count the number of edges that must be flipped. Now we start a DFS from node 0 and work our way down the tree (from parent to child). If we come across an "original" edge during the traversal, that is, an edge labeled with a 1, we increase the count by one. We don't modify count if we come across an "artificial" edge. We can combine these two operations and perform count += sign where sign is either 0 or 1 indicating an "artificial" or "original" edge.
// We have our answer in count at the end of the traversal.

    int cnt=0;
    void dfs(vector<vector<pair<int,int>>>&al,int node,int parent){
        //vis[node];
        for(auto edges:al[node]){
            if(edges.first!=parent){
                cnt+=edges.second;
                dfs(al,edges.first,node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>al(n);
        for(auto points:connections){
            al[points[0]].push_back({points[1],1});
            al[points[1]].push_back({points[0],0});
        }
        dfs(al,0,-1);
        return cnt;
    }
};