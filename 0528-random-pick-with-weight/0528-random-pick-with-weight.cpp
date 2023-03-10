class Solution {
public:
    
    Solution(vector<int>& w) {
         double sum = 0;
        for(int e:w){
            sum += e;
        }
        double perfSum=0;
        for(int e:w){
            perfSum += ((double) e) /sum;
            idxs.push_back(perfSum);
        }
    }
    
    int pickIndex() {
     double randResult = (double)rand() / (double)RAND_MAX ;
        int l=0, r=idxs.size()-1;
        while(l<r){
            int mid_idx = (l+r)/2;
            if(idxs[mid_idx] == randResult){
                return mid_idx;
            }
            if(idxs[mid_idx] > randResult){
                r=mid_idx;
            }else {
                l=mid_idx+1;
            }
        }
        return r;
    }

    vector<double> idxs;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */