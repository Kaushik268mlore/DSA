class Solution {
public:
    //this solution will definitely give TLE
    // vector<long long> distance(vector<int>& nums) {
    //     vector<long long>res(nums.size(),0);
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=0;j<nums.size();j++){
    //             if(nums[i]==nums[j])res[i]+=abs(i-j);
    //         }
    //     }
    // return res;}
    //and this solution couldnt pass the last 3 cases...lol
    // vector<long long> distance(vector<int>& nums){
    //     unordered_map<long long,vector<long long>>m;
    //     long long n=nums.size();
    //     vector<long long>arr(n,0);
    //     for(long long i=0;i<n;i++){
    //         m[nums[i]].push_back(i);
    //     }
    //     for(long long i=0;i<n;i++){
    //         if(m.find(nums[i])!=m.end()){
    //             for(auto idx:m[nums[i]]){
    //                 if(idx!=i)arr[i]+=abs(idx-i);
    //             }
    //         }
    //     }
    // return arr;}
    //this one's the solution.
    vector<long long> distance(vector<int>& nums) {
        vector<long long> result(nums.size(),0);
        unordered_map<int,int> last,count;
        unordered_map<int,long> sum;
        for(int i=0;i<nums.size();i++) {
            if(last.count(nums[i]))
                result[i]=result[last[nums[i]]]+1L*count[nums[i]]*(i-last[nums[i]]);
            last[nums[i]]=i;
            count[nums[i]]++;
        }
        last.clear(),count.clear();
        for(int i=nums.size()-1;i>=0;i--) {
            if(last.count(nums[i]))
                sum[nums[i]]+=1L*count[nums[i]]*(last[nums[i]]-i);
            result[i]+=sum[nums[i]];
            last[nums[i]]=i;
            count[nums[i]]++;
        }
        return result;        
    }
};