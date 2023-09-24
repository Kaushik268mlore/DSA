class Solution {
public:
    int trap(vector<int>& height) {//two pointer approach
             int left_max = INT_MIN;
        int right_max = INT_MIN;
        
        int r = height.size()-1;
        int l = 0;
        
        int ans = 0;
        while(l<=r){
            if(left_max <= right_max){
                if(left_max <= height[l]){
                    left_max = height[l++];
                    continue;
                }
                ans += (left_max - height[l++]);
            }else{
                if(right_max <= height[r]){
                    right_max = height[r--];  
                    continue;
                }
                ans += (right_max - height[r--]);   
            }
        }        
        return ans;
       /*
       int trap(vector<int>& height)//stacks O(n)solution
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
    */
    }
};