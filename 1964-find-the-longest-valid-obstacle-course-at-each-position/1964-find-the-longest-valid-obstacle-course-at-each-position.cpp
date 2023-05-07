class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> v, ans;
        for (auto& n : obstacles){
            if (v.empty() || v.back() <= n) v.push_back(n);
            else *upper_bound(v.begin(), v.end(), n) = n;
            ans.push_back(upper_bound(v.begin(), v.end(), n) - v.begin());
        }
        return ans;
    }
};