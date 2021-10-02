/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0};
        int cnt = 1;
        if(!n) return res;
        while(n--){
            int len = res.size();
            for(int i = len-1;i >= 0;--i){
                res.emplace_back(cnt+res[i]);
            }
            cnt *= 2;
        }
        return res;
        //cnt *= 2;
    }
};
// @lc code=end

