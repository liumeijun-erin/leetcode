/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res{0};
        for(int i = 1;i <= n;++i){
            //参考答案，将数视作类似于string
            //递归想法，简化问题：10100==101 ==100+1
            int j = i;
            if(j & 1) res.push_back(res.back() + 1);
            else{
                while(!(j&1)) j >>= 1;
                res.push_back(res[j]);
            }
        }
        return res;
    }
};
// @lc code=end

