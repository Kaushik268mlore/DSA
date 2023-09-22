class Solution {
public:
    int findDuplicate(vector<int>& nums) {//using hashset  solution
        unordered_set<int>viewd;
        for(auto x:nums){
            if(viewd.count(x)){return x;}//insertion ,deletion and counting works in O(1) time.
            viewd.insert(x);
        }
        return -1;
    }
};//Overall time complexity is O(n)