// Topological sort + carry forward max color list to children, keep track of Max.
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(colors.size());
        vector<int> inDegree(colors.size(),0);
        vector<array<int,26>> colorCounts(colors.size());
        queue<int> q;
        int result=0;
        for(vector<int> &v:edges)
            adjList[v[0]].push_back(v[1]),inDegree[v[1]]++;
        for(int i=0;i<inDegree.size();i++)
            if(!inDegree[i])
                q.push(i);
        if(q.empty())
            return -1;
        int nodes=colors.size();
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            result=max(result,++colorCounts[node][colors[node]-'a']);
            if(--nodes<0)
                return -1;
            for(int &n:adjList[node]) {
                for(int i=0;i<26;i++) {
                    colorCounts[n][i]=max(colorCounts[n][i],colorCounts[node][i]);
                }
                if(--inDegree[n]==0)
                    q.push(n);
            }
        }
        if(nodes!=0)
            return -1;
        return result;
    }
};