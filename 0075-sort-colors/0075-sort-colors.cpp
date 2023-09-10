class Solution {
public:
   // void sortColors(vector<int>& nums) {
   //      unordered_map<int,int>map;
   //      vector<int>arr(nums.size());
   //      for(int x:nums)map[x]++;
   //      for(int i=0;i<map[0];i++)nums[i]=0;
   //      for(int i=map[0];i<size(nums);i++){
   //          if(i<map[0]+map[1])nums[i]=1;
   //          else nums[i]=2;
   //      }
   //  } //this one's brute force
    
    void sortColors(vector<int>& nums) {
//         DNF solution;
        int n=nums.size(),l=0,mid=0,r=n-1;
        while(mid<=r){
            switch(nums[mid]){
                case 0:
                    swap(nums[mid++],nums[l++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[r--]);
                    break;
            }
        }
    }
};