#define LL long long
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({ roads[i][1], roads[i][2] });
            adj[roads[i][1]].push_back({ roads[i][0], roads[i][2] });
        }

        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
        vector<LL> dist(n, LLONG_MAX);
        vector<LL> ways(n, 0);

        ways[0] = 1;
        dist[0] = 0;
        pq.push({ 0, 0 });

        while (!pq.empty()) {
            LL dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nb : adj[node]) {
                LL edge = nb.second;
                int currnode = nb.first;
                if (dis + edge < dist[currnode]) {
                    dist[currnode] = dis + edge;
                    pq.push({ dist[currnode], currnode });
                    ways[currnode] = ways[node];
                } else if (dis + edge == dist[currnode]) {
                    ways[currnode] = (ways[currnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
