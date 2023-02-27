class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        // a very interesting problem here , so will be using a monotonic stack to solve the problem
        vector<pair<int,int>>s;//we'll be storing (start index , height) of each block of histogram.
        int res=0,n=size(height);
        for(int i=0;i<n;i++){
            int start=i;
            while(s.size()!=0&&s.back().second>height[i]){
                int id=s.back().first,h=s.back().second;
                s.pop_back();
                res=max(res,h*(i-id));//h is the height that it has extended , till i from start, which is stored in the stack.
                start=id;
            }
            s.push_back({start,height[i]});
        }
        //cout<<res<<" ";
        for(int i=0;i<s.size();i++){//check the remaining values in the stack, these will be the ones that can be extended till the end. so area would be height*(end -start)
            int h=s[i].second;
            res=max(res,h*(n-s[i].first));
        }
    return res;}
};