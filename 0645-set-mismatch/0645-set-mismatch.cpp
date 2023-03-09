class Solution {
public:
    // vector<int> findErrorNums(vector<int>& nums) {//pretty easy problem , can be easily solved using the hashmap. My approach , pretty messed up
    //     int twice,missing;
    //     unordered_set<int>s;
    //     for(int i=0;i<size(nums);i++){
    //         if(s.count(nums[i]))twice=nums[i];
    //         else s.insert(nums[i]);
    //     }
    //     int cnt=0;
    //     //int minn=*min_element(nums.begin(),nums.end());
    //     int maxx=*max_element(nums.begin(),nums.end());
    //     for(int i=1;i<=maxx;i++){
    //         if(s.count(i)==0){cnt++;missing=i;break;}
    //     }
    //     cout<<missing<<"\n";
    //     if(s.size()==1&&nums[0]==1)missing=twice+1;
    //     else if(cnt==s.size())missing=maxx+1;
    //     // else if(s.size()==1&&nums[0]!=1)missing=twice-1;
    // return {twice,missing};
    // }
    vector<int> findErrorNums(vector<int>& nums) {//actually an easy one , all u need to realise is what'd u go missing about.
        vector<int> result(2, -1); 
        for(int i=0; i<nums.size(); ++i){
            while(nums[i] != i+1){
                if(nums[i] == nums[nums[i]-1]){
                    result[0] = nums[i];
                    result[1] = i+1; 
                    break; 
                }else      
                    swap(nums[i], nums[nums[i]-1]); 
            }
        }
        return result;}
};