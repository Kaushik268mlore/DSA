class Solution {
public:
// man my greedy thinking has gotten worse...lol gotta grind more nowwww!
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& newiv) {
        int n=iv.size();
        int i=0;
        vector<vector<int>>res;
        while(i<n&&newiv[0]>iv[i][1]){
            res.push_back(iv[i]);
            i++;
        }
        while(i<n&&newiv[1]>=iv[i][0]){
            newiv[0]=min(newiv[0],iv[i][0]);
            newiv[1]=max(newiv[1],iv[i][1]);
            i++;
        }
        res.push_back(newiv);
        while(i<n){
            res.push_back(iv[i]);
            i++;
        }
        return res;
    }
};