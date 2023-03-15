class Solution {
public:
    int majorityElement(vector<int>& nums) {
       //solving using moore's  voting algorithm
            int count=0,n=nums.size(),maj;
        for(int i=0;i<n;i++){
            if(count==0){
                maj=nums[i];
            }
            count+=(nums[i]==maj)?1:-1;
        }
        return maj;
    }
    
};