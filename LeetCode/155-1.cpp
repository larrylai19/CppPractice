class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> minstack;
    
    MinStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    
    void push(int x) {
        minstack.push_back(x);
    }
    
    void pop() {
        minstack.pop_back();
    }
    
    int top() {
        return minstack.back();
    }
    
    int getMin() {
        return *(min_element(minstack.begin(), minstack.end()));
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