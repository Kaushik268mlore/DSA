class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=size(gas),start=0;
        int totalgas=0,curgas=0;
        for(int i=0;i<n;i++){
            int add=gas[i]-cost[i];
            totalgas+=add;
            curgas+=add;
            if(curgas<0){
                curgas=0;
                start=i+1;
            }
        }
         return (totalgas<0)?-1:start;
    }
};