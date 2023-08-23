class Solution {
public:
//     stack problem....
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>res(nums.size(),-1);
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty()&&nums[s.top()]<=nums[i%nums.size()])s.pop();
            // res[i%nums.size()]=
            if(s.empty())res[i%nums.size()]=-1;
            else res[i%nums.size()]=nums[s.top()];
            s.push(i%nums.size());
        }
    return res;}
};