class Solution {
public:
//    form a graph and just DFS/BFS through it .. tbh a simple question I had an idea..... now lemme implement it..
    int dfs(int i, vector<vector<int>> &m, vector<int>& informTime, int mx = 0) {
    for (auto d : m[i])
        mx = max(mx, dfs(d, m, informTime));
    return informTime[i] + mx;
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> m(n);
    for(auto i = 0; i < manager.size(); ++i)
        if (manager[i] != -1)
            m[manager[i]].push_back(i);
    return dfs(headID, m, informTime);
}
};