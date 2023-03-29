class Solution {
public:
    // a greedy solution for the problem, hopefully it'll work
    // [-1,-8,0,5,-9]->sort -> [-9,-8,-1,0,5] 
    //the largest number also has to be multiplied in the end, so in that case we'll have to include the smaller dishes  just to get the bigger time value
    //lets suffix sum on the sorted array and note the index where the (sum is < 0 ) and the next item/food should be the starting point to contribute to the coefficient .
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int n=sat.size();
        int start=n-1,tot=0;
        for(int i=n-1;i>=0;i--){
            tot+=sat[i];
            if(tot<0)break;
            start--;
        }
        start++;
        int t=1,coeff=0;
        for(int i=start;i<n;i++,t++){
            coeff+=(t*sat[i]);
        }
    return coeff;}
};