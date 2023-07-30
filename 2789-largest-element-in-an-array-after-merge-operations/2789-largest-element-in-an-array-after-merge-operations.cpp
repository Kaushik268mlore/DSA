#define LL long long
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        LL n=nums.size(),res=0;
        stack<LL>s;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0)s.push(nums[i]);
            else if(s.top()<nums[i]){
                s.push(nums[i]);
            }
            else {
                LL top=s.top();
                s.pop();
                top+=nums[i];
                s.push(top);
            }
            res=max(res,s.top());
        }
    return res;
    }
};