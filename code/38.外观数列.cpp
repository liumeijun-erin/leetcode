/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string pre  = "1",cur = "1";
        int i = 0,pos = 0;
        char c;
        while(--n){
            cur = "";
            i = 0;
            while(i < pre.size()){
                c = pre[i];
                pos = i;
                while(i < pre.size()&&pre[i] == c) ++i;
                cur += to_string(i-pos);
                cur += c;
            }
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

