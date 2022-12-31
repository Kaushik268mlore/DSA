class Solution {
public:
   void sortColors(vector<int>& nums) {
        unordered_map<int,int>map;
        vector<int>arr(nums.size());
        for(int x:nums)map[x]++;
        for(int i=0;i<map[0];i++)nums[i]=0;
        for(int i=map[0];i<size(nums);i++){
            if(i<map[0]+map[1])nums[i]=1;
            else nums[i]=2;
        }
    }
};