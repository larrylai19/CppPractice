class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> minstack;
    
    MinStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    
    void push(int x) {
        if(minstack.empty() || minstack.top().second >= x)
            minstack.push({x, x});
        else
            minstack.push({x, minstack.top().second});
    }
    
    void pop() {
        minstack.pop();
    }
    
    int top() {
        return minstack.top().first;
    }
    
    int getMin() {
        return minstack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */