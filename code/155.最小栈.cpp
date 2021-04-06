/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    //tip:use assisting stack
    //always check if stack is empty when using .top
    //modification1:why store minIndex when you can store minNum
    //vector<int> s;
    stack<int> s;
    stack<int> minStack;
    //int min;
    MinStack() {
        //min = 0;
        minStack.push(0x7fffffff);//faster
    }
    
    void push(int val) {
        minStack.push(min(val,minStack.top()));
        s.push(val);
        /*if(s.size() == 0 || val < minStack.top()){
            minStack.push(val);
        }
        else{
            minStack.push(minStack.top());
        }
        s.push(val);*///faster
    }
    
    void pop() {
        minStack.pop();
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

