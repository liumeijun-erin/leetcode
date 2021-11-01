/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        for(const int& c:candyType) s.insert(c);
        return min(s.size(),candyType.size()/2);
    }
};
// @lc code=end

