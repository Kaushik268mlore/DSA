class Solution {
public:
    //this is a normal mapping and sorting implementation, which will be in O(nlogn) 
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string,int>mp;
//         int l=k;
//         for(int i=0;i<words.size();i++){
//             mp[words[i]]++;
//         }
//         vector<pair<int,string>>res;
//         for(auto it:mp){
//             res.push_back({it.second,it.first});
//         }
//         // priority_queue<pair<int,string>>p;
//         // for(auto pp:mp){
//         //     p.push({pp.second,pp.first});
//         // }
//         // while(k){
//         //     res.push_back(p.top());
//         //     p.pop();
//         //     k--;
//         // }
//         sort(res.begin(),res.end(),[&](pair<int,string>&a,pair<int,string>&b)->bool{
//             if(a.first == b.first)
//                 return a.second<b.second;
            
//             return a.first>b.first;
//         });
//         vector<string>ans(l);
//         for(int i=0;i<l;i++){
//             ans[i]=res[i].second;
//         }
//     return ans;}
    //this is another approach using custom heaps and TC: o(nlogk)
    struct comp{
        bool operator()(pair<string,int>a,pair<string,int>b){
            return a.second>b.second||(a.second==b.second && a.first<b.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k){
        priority_queue<pair<string,int>,vector<pair<string,int>>,comp>pq;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
            if(pq.size()>k)pq.pop();
        }
        vector<string>res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=pq.top().first;
            pq.pop();
        }
    return res;}
};