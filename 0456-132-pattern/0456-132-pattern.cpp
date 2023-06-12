class Solution {
public:
// as for the tradition of writing brute-force
    // bool find132pattern(vector<int>& arr) {
    //     int n=arr.size();
    //     for(int i=1;i<n-1;i++){
    //         if(arr[i-1]<arr[i+1]&&arr[i+1]<arr[i])return true;                       
    //     }
    // return false;
    // }
// sorry,my bad understanding of the problem
    bool find132pattern(const std::vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }
    
    std::stack<int> stk;
    int s3 = INT_MIN;
    
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] < s3) {
            return true;
        } else {
            while (!stk.empty() && nums[i] > stk.top()) {
                s3 = stk.top();
                stk.pop();
            }
        }
        stk.push(nums[i]);
    }
    
    return false;
}
};