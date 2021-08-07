/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        do{

            int ch = (--columnNumber)%26;
            res.insert(res.begin(),ch +'A');
            columnNumber /= 26;
        }while(columnNumber);
        return res;
    }
};
// @lc code=end

