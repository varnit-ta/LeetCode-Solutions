class MinStack {
public:
    stack<int> s, minStack;
    
    void push(int val) {
        if ((!minStack.empty() && minStack.top() >= val) || (minStack.empty())){
            s.push(val);
            minStack.push(val);
        }else{
            s.push(val);
        }
    }
    
    void pop() {
        if (minStack.top() == s.top()) minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */