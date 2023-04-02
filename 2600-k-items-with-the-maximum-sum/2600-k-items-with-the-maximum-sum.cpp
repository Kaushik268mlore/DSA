class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int cnt=0;
        for(int i=0;i<k;i++){
          if(numOnes){cnt++;numOnes--;}
          else if(numZeros){cnt+=0;numZeros--;}
          else if(numNegOnes) {cnt--;numNegOnes--;}
        }
      return cnt;}
};