class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n =nums.size();
        int prod=0;
        for (auto i: nums){
        if(i<0)prod++;
            if(i==0) return 0;
        }
        if (prod%2==0) return 1;
        return -1;
        
    }
};