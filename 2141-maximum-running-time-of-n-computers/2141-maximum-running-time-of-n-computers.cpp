#define LL long long
class Solution {
public:
    LL maxRunTime(int n, vector<int>& b) {
      LL sum=accumulate(b.begin(),b.end(),0LL);
        priority_queue<LL>pq(b.begin(),b.end());
        while(pq.top()>sum/n){
            sum-=pq.top();
            pq.pop();
            n--;
        }
    return sum/n;
    }
};