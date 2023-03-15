class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int tot=0;
        for(int i=left;i<=right;i++){
            tot+=(arr[i]);
        }
    return tot;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */