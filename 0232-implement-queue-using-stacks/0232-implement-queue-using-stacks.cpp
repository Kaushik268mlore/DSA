class MyQueue {//amazing easy question ,blown!
public:
        stack<int>arr1;
        stack<int>arr2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!arr1.empty()){
            arr2.push(arr1.top());
            arr1.pop();
        }
        arr1.push(x);
        while(!arr2.empty()){
            arr1.push(arr2.top());
            arr2.pop();
        }
    }
    
    int pop() {
        int r=arr1.top();
        arr1.pop();
        return r;
    }
    
    int peek() {
        return arr1.top();
    }
    
    bool empty() {
        return arr1.empty();
        //return arr1.size()==0?true:false;
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */