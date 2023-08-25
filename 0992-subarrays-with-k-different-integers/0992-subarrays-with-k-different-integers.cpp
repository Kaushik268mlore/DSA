class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
    int atMost(vector<int>arr,int k){
          int res=0;
        unordered_map<int,int>map;
        for(int i=0,j=0;i<arr.size();++i){
             if(!map[arr[i]]++){k--;}
             while(k<0){
              if(!--map[arr[j]]){k++;}
              j++;
            }
            res+=i-j+1;
        }
        return res;
    }
};