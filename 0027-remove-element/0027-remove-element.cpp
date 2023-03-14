class Solution {
public:
   //totally devastated by what the problem was supposed to solve ...lol
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<size(nums);i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
    return j;
    }
};