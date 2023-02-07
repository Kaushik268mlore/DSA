class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {// an easy implementation based problem, there is a normal append to a new array solution,but the below solution is much more efficient because it is in place array solution and uses o(1) space :).
        for(int i = 0; i < n; i++){
            nums[i] += nums[n + i] * 10000;
        }
       // at this point nums = [x1y1, x2y2, x3y3, y1, y2, y3].
        
       // we fill in the array values from the end, so as not to overwrite the calculated numbers in previous step
      // at the end of one iteration nums will be [x1y1, x2y2, x3y3, y1, x3, y3 ]
        for(int i = n - 1; i >= 0; i--){
            nums[2 * i + 1] = nums[i] / 10000;
            nums[2 * i] = nums[i] % 10000;
        }
        
        return nums;
    }
};