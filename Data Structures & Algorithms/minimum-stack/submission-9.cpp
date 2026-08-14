class MinStack {
public:
    std::stack<int> stk_;
    std::stack<int> min_stk_;
    
    MinStack() {
        
    }
    
    void push(int val) {
        stk_.push(val);
        if(min_stk_.empty()) {
            min_stk_.push(val);
        } else {
            int top_min_stk = min_stk_.top();
            if(val < top_min_stk){
                min_stk_.push(val);
            }else{
                min_stk_.push(top_min_stk);
            }
        }
    }
    
    void pop() {
        stk_.pop();
        min_stk_.pop();
    }
    
    int top() {
        return stk_.top();
    }
    
    int getMin() {
        return min_stk_.top();
    }
};
