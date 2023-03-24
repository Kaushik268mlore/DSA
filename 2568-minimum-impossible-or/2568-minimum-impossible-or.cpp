class Solution {
public:
    // a little bit logical is all this is... more like brain teaser
    int minImpossibleOR(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=1;;i<<=1){
            if(s.find(i)==s.end())return i;
    }
        return maxx+1;
        }
};