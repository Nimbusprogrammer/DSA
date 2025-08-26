class MinStack {
public:
stack<long long> st;
//one method is creating 2 stacks another tracking minimas and when popping if st1.top() == mins.top() then pop mins stack too. so now new mins.top() will be the updated minimum
long long mini;//don't initialize with INT_MIN  as when you do 2*val-mini it goes out of bounds
    MinStack() {
        
    }
    
    void push(int val) {
        if ( st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if ( val < mini)
        {
            st.push(2LL*val-mini);
            mini = val;
        }
        else 
        st.push(val);

    }
    
    void pop() {
        if ( st.top() < mini )
        {
            mini = 2*mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if ( st.top() < mini)
        return mini;
        else 
        return st.top();
    }
    
    int getMin() {
        return mini;
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