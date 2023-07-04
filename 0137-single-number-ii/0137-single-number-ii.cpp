class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int orbits=0;
        
        int shft=0, i,ans=0;
        
        for( i=0;i<32;i++)
        {
            int sum=0;
            for(int x:nums)
            {
                if((x&(1<<shft)))
                {
                    sum++;
                }
                
            }
            if(sum%3==1)
            {
                ans=(ans|(1<<shft));
            }
            shft++;
        }
        
        return ans;
    }
};