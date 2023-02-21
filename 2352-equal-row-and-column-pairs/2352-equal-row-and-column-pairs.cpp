class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res=0;
        map<vector<int>,int>mp;
        for(int i=0;i<grid.size();i++)mp[grid[i]]++;
        for(int i=0;i<grid[0].size();i++){
            vector<int>dummy;
            for(int j=0;j<grid.size();j++){
                dummy.push_back(grid[j][i]);
            }
            int exists=mp[dummy];
            if(exists>0)res+=exists;
        }
        return res;
    }
};