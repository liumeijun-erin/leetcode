/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 1) return preorder[0] == '#';
        stack<int> left_done;
        int pos = 0;
        while (pos < preorder.size()) {
            if (preorder[pos] == '#') {
                pos = pos + 2;
                while(!left_done.empty() && left_done.top() == 1) left_done.pop();
                if(!left_done.empty()) left_done.top() = 1;
                else break;
            }
            else {
                while (pos < preorder.size() && preorder[pos] != ',') ++pos;
                ++pos;
                left_done.emplace(0);
            }
        }
        //cout<<left_done.size()<<" "<<pos<<" "<< preorder.size()<<endl;
        return (left_done.empty() && pos == preorder.size() + 1);
    }
};
// @lc code=end

