/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    //整体思路正确但是没写出来，参考答案重新整理思路更清晰之后过了
    //1-由调用方式得所有处理在hasNext中处理完成，循环到一个int
    //2-使用->更直观！
    stack<pair<vector<NestedInteger>::iterator,vector<NestedInteger>::iterator> >s;
public:
    NestedIterator(vector<NestedInteger> &nestedList){
        s.emplace(nestedList.begin(),nestedList.end());
    }
    int next() {
        return s.top().first++->getInteger();
    }
    bool hasNext() {
        while(!s.empty()){
            //自己写的，没过
            if(s.top().first == s.top().second) {
                s.pop();
                if(!s.empty()) ++s.top().first;
            }
            else if(s.top().first->isInteger()) return true; 
            else{
                vector<NestedInteger>& tmp = s.top().first->getList();
                s.emplace(tmp.begin(),tmp.end());
            } 
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

