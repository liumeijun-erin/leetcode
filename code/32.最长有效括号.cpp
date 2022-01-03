/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    // 四种解法都很妙~
    // string-dp, 正向逆向两次遍历结局问题,stack动态存储段first-last
    
    // solution1：使用状态数组记录是否合理，再遍历状态数组得到len
    // 由于"()(()",不能简单用left_cnt,right_cnt判断是否合理，也不能用min(left_cnt,right_cnt)*
    // 还要保证连续合理 so-> 状态数组
    // key pnt：状态记录数组，栈记录一下合理能被消掉的
    // int longestValidParentheses(string s)
    // {
    //     vector<bool> fixed(s.size());
    //     stack<int> leftq;
    //     for (int i = 0; i < s.size(); ++i) {
    //         if (s[i] == '(') leftq.emplace(i);
    //         else if(!leftq.empty()){
    //             fixed[leftq.top()] = 1;
    //             leftq.pop();
    //             fixed[i] = 1;
    //         }
    //     }
    //     int pos = 0;
    //     int res = 0;
    //     while (pos < fixed.size()) {
    //         while(pos < fixed.size() && fixed[pos] == 0) ++pos;
    //         int pre = pos;
    //         while(pos < fixed.size() && fixed[pos] == 1) ++pos;
    //         res = max(pos - pre, res);
    //     }
    //     //"()(()"
    //     //")(((((()())()()))()(()))("
    //     //"((()()(()((()"
    //     return res;
    // }

    // solution2：参考答案!改进--不使用状态数组.而是用stack动态记录段情况first，last
    // key pnt：stack中不只存left_bracket_id 而是当前动态段的记录
    // int longestValidParentheses(string s)
    // {
    //     stack<int> sid;
    //     sid.emplace(-1);  // 记录起点--sid.top()+1
    //     int res = 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         if (s[i] == '(') sid.emplace(i);
    //         else {
    //             sid.pop();
    //             if (sid.empty()) {
    //                 // )多，从i+1才有可能
    //                 sid.emplace(i);
    //             }
    //             else {
    //                 res = max(res, i - sid.top());
    //             }
    //         }
    //     }
    //     return res;
    // }

    // solution3：参考答案，利用left_cnt,right_cnt实现
    // 解决"()(()"情况
    // key pnt：使用两次遍历解决!!!正向+ 逆向！！！
    // int longestValidParentheses(string s)
    // {
    //     int len = 0, left_cnt = 0, right_cnt = 0;
    //     for (const char& c: s) {
    //         if (c == '(') ++left_cnt;
    //         else ++right_cnt;
    //         if (right_cnt > left_cnt) {
    //             left_cnt = 0;
    //             right_cnt = 0;
    //         }
    //         else if(right_cnt == left_cnt) len = max(2*right_cnt ,len);
    //     }
    //     left_cnt = 0;
    //     right_cnt = 0;
    //     for (int i = s.size()-1; i >= 0; --i) {
    //         if (s[i] == ')') ++right_cnt;
    //         else ++left_cnt;
    //         if (right_cnt < left_cnt) {
    //             left_cnt = 0;
    //             right_cnt = 0;
    //         }
    //         else if(right_cnt == left_cnt) len = max(2*right_cnt ,len);
    //     }
    //     return len;
    // }
    
    // solution4：参考答案dp--dp[i]为以i为结尾的最长串，再求max(dp)
    // "(())()()()(())"
    // dp['('] = 0
    // dp[n] = n-1:')' -> n - 1- dp[n-1] =='('?dp[n-1]+2:0) + dp[n-2-dp[n-1]]
    //         n-1:'(' -> dp[n-2]+2
    int longestValidParentheses(string s)
    {
        int len = 0;
        vector<int> dp(s.size(),0);
        if (s[0] =='(' && s[1] == ')') {
            dp[1] = 2;
            len = 2;
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '(') continue;
            if (s[i-1] == ')') {
                if (i-1-dp[i-1] >= 0&&s[i-1-dp[i-1]] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (i-2-dp[i-1] >= 0) dp[i] += dp[i-2-dp[i-1]];
                    len = max(len, dp[i]);
                }
            }
            else {
                dp[i] = dp[i-2] + 2;
                len = max(len, dp[i]);
            }
        }
        return len;
    }


};
// @lc code=end
