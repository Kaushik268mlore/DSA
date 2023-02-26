class Solution {
public:/// totally relied on the discussion page.. more problems on these will be solved.
    vector<int> parent;
    void dsu(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;

	}
    int findParent(int u) {
		return parent[u] = (parent[u] == u ? u : findParent(parent[u]));
	}

	void _union(int u, int v) {
		int pv = findParent(v);
		int pu = findParent(u);

		if (pv != pu) parent[pv] = pu;
	}
    void doswaps(int i,int j,vector<int>&arr,vector<int>&t){
        if(arr[i]==t[i]){
            if(arr[j]==t[j])void();
            
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        dsu(n);
        for(auto &arr:allowedSwaps){
            _union(arr[0],arr[1]);
        }
        int res=0;
        unordered_map<int,multiset<int>>mp;
        for (int i = 0; i < n; i++) {
			mp[findParent(i)].insert(source[i]);
		}

		for (int i = 0; i < n; i++) {

			if (!mp[findParent(i)].count(target[i])) res++;
			else  {
				mp[findParent(i)].erase(mp[findParent(i)].find(target[i]));
			}
		}
    return res;}
};