class Solution {
public:
    // hashing&&heap implementation, this one's more like a simulation problem
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});
        vector<int>v(nums.size(),0);
        long long ans=0;
        while(!pq.empty())
        {
            int i=pq.top().second;
            if(v[i]==0)
            {
                v[i]=1;
                if(i-1>=0)
                    v[i-1]=1;
                if(i+1<nums.size())
                    v[i+1]=1;
                v[i]=1;
                ans+=pq.top().first;
            }
            pq.pop();
        }
        return ans;
    }
};