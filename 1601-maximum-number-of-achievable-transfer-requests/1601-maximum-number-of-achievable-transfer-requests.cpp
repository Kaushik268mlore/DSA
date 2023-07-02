class Solution {
    int res = 0;
public:
    void fun(int idx, int used, vector<vector<int>> &r, vector<int> &v)    {
        if(idx==r.size())   {
            //checking if current recurrence result is useful or not, by cheecking the constraint of in == out for all buildings
            bool can_take = true;
            for(auto it : v)    {
                if(it!=0)   {   can_take = false;   }
            }
            //updating res if possible
            if(can_take)    
                res = max(res,used);
            return ;
        }

        //i->from building & j->to building
        int i=r[idx][0];
        int j=r[idx][1];

        //considering current request
        v[i] -= 1;
        v[j] += 1;
        fun(idx+1, used+1,r,v);

        //BACKTRACKING : not considering current request
        v[i] += 1;
        v[j] -= 1;
        fun(idx+1, used,r,v);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n,0);
        fun(0,0,requests,v);

        return res;
    }
};