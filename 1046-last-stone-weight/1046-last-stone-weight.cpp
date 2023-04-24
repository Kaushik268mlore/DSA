class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {//max heap problem
        priority_queue<int>mxhp(stones.begin(),stones.end());
        while(mxhp.size()>1){
            int x=mxhp.top();
            mxhp.pop();
            int y=mxhp.top();
            mxhp.pop();
            if(x-y>0)mxhp.push(x-y);
        }
        if(mxhp.size()==0)return 0;
        return mxhp.top();
    }
};