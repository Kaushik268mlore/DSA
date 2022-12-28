class Solution {
public:
   /* int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());
        //for(int x:piles)pq.push(x);
        int res=accumulate(piles.begin(),piles.end(),0);
        
        for(int i=0;i<k;i++){
            int a=pq.top();
            pq.pop();
            pq.push(floor(a/2));
            res-=a;
        }
        
        //for(int x:pq)res+=x;
        return res;
    }*/
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        
        for (int i = 0; i < k; i++) {
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }
        
        return totalSum;
    }
};