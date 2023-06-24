class Solution {
public:
       int tallestBillboard(vector<int>& rods) {
        const auto sum = reduce(rods.begin(), rods.end());
        // Difference cannot be larger than half of the sum.
        vector memo(rods.size(), vector(sum / 2 + 1, -1));
        return helper(rods, 0, sum / 2, 0, memo);
    }

    int helper(
        const vector<int>& rods,
        const size_t idx,
        const int limit,
        const int diff,
        vector<vector<int>>& memo) {

        if (idx == rods.size())
            return diff == 0 ? 0 : INT_MIN; // Using INT_MIN as a sentinel value works because the sum cannot be larger than 5000.

        if (diff > limit)
            return INT_MIN;

        auto& m = memo[idx][diff];
        if (m != -1)
            return m;

        return m = max({
            // Length does not change when we don't pick the rod.
            helper(rods, idx + 1, limit, diff, memo),
            // Length increases when we add the rod to the longer side.
            helper(rods, idx + 1, limit, diff + rods[idx], memo) + rods[idx],
            // Length increases depending on whether the rod is longer than the difference between the sides.
            helper(rods, idx + 1, limit, abs(diff - rods[idx]), memo) + (diff > rods[idx] ? 0 : rods[idx] - diff)});
    }
};