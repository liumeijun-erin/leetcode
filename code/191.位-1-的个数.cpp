/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // solution1:标准遍历，O(len)
        // int cnt = 0;
        // while(n){
        //     if(n%2) ++cnt;
        //     n /= 2;
        // }
        // return cnt;
        
        // solution2：n&(n-1)将n中最优一位的1变成n的结果O(len_of_1)
        // n &= (n-1)作用！
        int cnt = 0;
        while (n) {
            n &= (n-1);
            ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

