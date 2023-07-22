class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int brkpt=-1;
        for(int i=nums.size()-1;i>0;i--){//this loop is to find the breakpoint
            if(nums[i]>nums[i-1]){
                brkpt=i-1;break;
            }
        }
        if(brkpt==-1){
            reverse(nums.begin(),nums.end());//if the breakpoint is not found,then the next permutation is the reverse of the whole array 
            return;
        }
        for(int i=nums.size()-1;i>=brkpt;i--){
            if(nums[i]>nums[brkpt]){//finds any element greater than the element at the breakpoint within the breakpoint region
                swap(nums[i],nums[brkpt]);//inorder to get the next permutation we just need to reverse the subarray from the breakpoint till the end.
                reverse(nums.begin()+brkpt+1,nums.end());
                break;
            }
        }
    }
};