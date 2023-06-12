class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       string temp="";
       vector<string> ans;
       if(nums.size()==0)
       {
           return ans;
       }
       int initial=nums[0];
       temp+=to_string(initial);
       bool single=true;
       for(int i=1;i<nums.size();i++)
       {
           if(nums[i]!=initial+1)
           {
               if(!single)
               {
               temp+="->";
               temp+=to_string(initial);
               }
               ans.push_back(temp);
               single=true;
               temp=to_string(nums[i]);
           }
           else
           {
               single=false;
           }
           initial=nums[i];
       }
        if(!single)
       {
         temp+="->";
        temp+=to_string(initial);
       }
       ans.push_back(temp);
       return ans;
   }
};