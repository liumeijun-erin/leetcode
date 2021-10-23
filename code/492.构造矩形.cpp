/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int a = sqrt(area);
        while(a>0){
            if(area % a == 0) break;
            --a;
        }
        return vector<int> {area/a,a};
    }
};
// @lc code=end

