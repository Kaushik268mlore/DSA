#define LL long long 
class Solution {
public:
//     I can think of something greedy
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       vector<pair<int,int>>ag(n);
        for(int i=0;i<n;i++){
            ag[i]=make_pair(efficiency[i],speed[i]);
        }
        sort(ag.rbegin(),ag.rend());
        priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>>pq;
//         speed,efficiency
        LL sum=0;
        LL res=LLONG_MIN;
        for(int i=0;i<n;i++){
            sum+=ag[i].second;
            pq.push({ag[i].second,ag[i].first});
            if(pq.size()>k){
                sum-=pq.top().first;
                pq.pop();
            }
            res=max(res,sum*ag[i].first);
        }
    return res%mod;
}
};