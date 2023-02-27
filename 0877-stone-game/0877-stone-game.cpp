class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice =0,bob=0;
        priority_queue<int>pq(piles.begin(),piles.end());
        for(int i=0;i<piles.size();i++){
            if(i&1){
                bob+=pq.top();
                pq.pop();
            }
            else {
                alice+=pq.top();
                pq.pop();
            }
        }
    return alice>bob;
    }
};