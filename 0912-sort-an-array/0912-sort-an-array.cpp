class Solution {
public:
    // vector<int> sortArray(vector<int>& nums) {/// hahahahaha just kidding .
    //     sort(nums.begin(),nums.end());
    //     return nums;
    // }
    // vector<int> sortArray(vector<int>& nums){ // this is using heap , basically didnt implement the heap but STL has similar implementation.
    //     priority_queue<int>pq(nums.begin(),nums.end());
    //     vector<int>res;
    //     while(!pq.size()){
    //         res.push_back(pq.top());
    //         pq.pop();
    //     }
    // return res;}
    void Csort(vector<int>&arr){// this basically is an HashMap based Implementation where u count the no.of elements and then push it to ur resultant array. pretty simple and efficient method as well , all at the cost of an extra space to implement the HashMap :) It's kinda worth it though
        unordered_map<int,int>map;
        for(int i=0;i<size(arr);i++){map[arr[i]]++;}
        int lo=*min_element(arr.begin(),arr.end());
        int hi=*max_element(arr.begin(),arr.end());
        int id=0;
        for(int i=lo;i<=hi;i++){
            while(map[i]){
                arr[id]=i;
                map[i]--;
                id++;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums){
        Csort(nums);
    return nums;}
};