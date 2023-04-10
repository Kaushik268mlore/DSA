class Solution {
public:
    bool isPrime(int num) {
        if(num<=1)
            return false;
        for(int i=2;i*i<=num;i+=1+(i&1))
            if(num%i==0)
                return false;
        return true;
    }
        int diagonalPrime(vector<vector<int>>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<nums[0].size();j++) {
                if(i==j||i+j+1==nums[0].size())
                    if(isPrime(nums[i][j]))
                        result=max(result,nums[i][j]);
            }
        return result;
        }
        
    // return mp;}
};