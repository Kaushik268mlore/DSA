class Solution {
public:
    // cool hashing solution O(N)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1)return 0;
        unordered_set<int>s(nums.begin(),nums.end());
        int res=1;
        int currstk=0,currnum=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                currnum=nums[i];
                currstk=1;
            }
            while(s.find(currnum+1)!=s.end()){
                currnum++;
                currstk++;
            }
        res=max(currstk,res);
        }
    return res;
    }
};