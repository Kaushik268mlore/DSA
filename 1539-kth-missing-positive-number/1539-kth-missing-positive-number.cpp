class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    for(int i:arr){if(i<=k)k++;}//this isn't my logic , but is some really good shit..
        return k;
    }
};