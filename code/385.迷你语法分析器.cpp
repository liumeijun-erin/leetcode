  /*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> s_nested;
        NestedInteger tmp;
        for(int i = 0;i < s.size();++i){
            if(s[i] == ',') continue;
            else if(s[i] == '[') {
                s_nested.emplace(NestedInteger());
            }
            else if(s[i] == ']') {
                tmp = s_nested.top();
                s_nested.pop();
                if(!s_nested.empty()) s_nested.top().add(tmp);
            }
            else {
                //审题可能为-
                bool isNeg = false;
                if(s[i] == '-'){
                    isNeg = true;
                    ++i;
                }
                int num = 0;
                while(i < s.size()&&s[i]>='0'&&s[i]<='9'){
                    num = num*10+(s[i++]-'0');
                }
                --i;
                if(isNeg) num = -num;
                tmp = NestedInteger(num);
                if(s_nested.empty()) return tmp;
                else s_nested.top().add(tmp);

            }
        }
        return tmp;
    }
};
// @lc code=end

