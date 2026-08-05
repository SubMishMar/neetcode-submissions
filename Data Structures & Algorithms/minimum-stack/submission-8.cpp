class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        int min_element;
        if (min_stk.size() == 0 || val < min_stk.back()) {
            min_stk.push_back(val);
        } else {
            min_stk.push_back(min_stk.back());
        }
    }
    
    void pop() {
        stk.pop_back();
        min_stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_stk.back();
    }

    std::vector<int> stk;
    std::vector<int> min_stk;
};
