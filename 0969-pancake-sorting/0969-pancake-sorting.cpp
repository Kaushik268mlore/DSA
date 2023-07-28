class Solution {
public:
//     okay considering that the elements range from [0,n], that helps for some reason
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int>res;
        for(int i=n-1;i>=0;i--){
            int id=find(arr.begin(),arr.end(),i+1)-arr.begin();
            res.push_back(id+1);
            res.push_back(i+1);
            reverse(arr.begin(),arr.begin()+id+1);
            reverse(arr.begin(),arr.begin()+i+1);
        }
    return res;
    }
};