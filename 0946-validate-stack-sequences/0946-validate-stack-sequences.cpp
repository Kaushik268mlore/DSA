class Solution {
public:
    // in the popped array there should exist no pivot or at most one pivot and all the elements must exist in the pushed array.
    //else we can a stack
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // int n=pushed.size();
        // int j=0;
        // stack<int>s;
        // for(int i=0;i<n;i++){
        //     s.push(pushed[i]);
        //     while(s.top()==popped[j]&&s.size())s.pop(),j++;
        // }
        // return s.empty();
        stack<int> stack;
        int i = 0;
        for (int x : pushed) {
            stack.push(x);
            while (stack.size() && stack.top() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.size() == 0;
    }
};