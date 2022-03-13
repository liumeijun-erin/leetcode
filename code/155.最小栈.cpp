/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    stack<int> minStack;
    stack<int> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (s.empty() || val <= minStack.top()) minStack.emplace(val);
        s.emplace(val);
    }
    
    void pop() {
        if (s.top() == minStack.top()) minStack.pop();
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
// @lc code=end

