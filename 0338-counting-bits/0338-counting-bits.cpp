class Solution {
public:
    vector<int> countBits(int n) {
      vector<int>arr;
      for(int i=0;i<=n;i++){
          arr.push_back(__builtin_popcount(i));
      }
    return arr;}
};