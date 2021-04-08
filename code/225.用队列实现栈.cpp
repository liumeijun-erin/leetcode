/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num;
        if(q1.empty()){
            num = q2.back();
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
        else{
            num = q1.back();
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        return num;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) return q2.back();
        else return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

