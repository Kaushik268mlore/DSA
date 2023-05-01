class Solution {
public:
    double average(vector<int>& salary) {
        // sort(salary.begin(),salary.end());
        double sum=accumulate(salary.begin(),salary.end(),0);
        double min=*min_element(salary.begin(),salary.end());
        double max=*max_element(salary.begin(),salary.end());
        sum-=min;sum-=max;
        int n=salary.size();
        return sum/double(n-2);
        // for(int i=1;i<n-1;i++)
    }
};